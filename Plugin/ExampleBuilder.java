package tc_plugin;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

import com.topcoder.client.contestant.ProblemComponentModel;
import com.topcoder.shared.language.Language;
import com.topcoder.shared.problem.Renderer;
import com.topcoder.shared.problem.DataType;
import com.topcoder.shared.problem.TestCase;

/**
 * @author kyky
 *
 * This test generator class is for Java, C#, and C++.
 * It is based on PopsProcessor which is a Java-only test generator developed by Tim Roberts.
 * 
 * This code works only with code templates specifically written for compatibility with the plugin.
 * The templates for each supported language are in the templates directory of this source distribution. 
 */
public class ExampleBuilder {
    /**
     * Obtains a list of user-defined tags.
     * @return a list of user-defined tags.
     */
    public Map getUserDefinedTags() {
        return tags;
    }
    /**
     * 
     * @param src
     * @param problem
     * @param lang
     * @param rend
     * @return
     */
    public String preProcess(
        String src,
        ProblemComponentModel problem,
        Language lang,
        Renderer rend) {

        tags.put(WRITERCODE, problem.getDefaultSolution());
        // If the source not equal to the default solution, return the existing source
        if (src != null && src.length() > 0 && !src.equals(problem.getDefaultSolution()) && sameLanguage( lang, src ) ) {
            return src;
        }
        if (!problem.hasSignature()) {
            tags.put(MAINBODY, "// Problem has no signature");
            return src;
        }
        if (!Arrays.asList(supported).contains(lang.getName())) {
            return src;
        }
        TestCase[] tests= problem.getTestCases();
        DataType[] pt= problem.getParamTypes();
        String[] pn = problem.getParamNames();
        StringBuffer buf= new StringBuffer();

        if ( tests != null ) {
            for (int i= 0; i != tests.length; i++) {
                if ( needDef( lang ) ) {
                    buf.append( indent(lang)+"    {\n" );
                }
                String[] vals= tests[i].getInput();
                for (int j= 0; j != pt.length; j++) {
                    genValueDef(buf, pt[j], vals[j], lang, pn[j]);
                }
                genValueDef( buf, problem.getReturnType(), tests[i].getOutput(), lang, RETVAL );
                if ( needDef( lang ) ) {
                    buf.append(
                        indent(lang)
                    +   "        "
                    +   problem.getClassName()
                    +   " theObject;\n"
                    +   indent(lang)
                    +   "        eq("
                    +   (i)
                    +   ", theObject."
                    +   problem.getMethodName()
                    +   "(");
                } else {
                    buf.append(
                        indent(lang)
                    +   "        eq("
                    +   (i)
                    +   ",(new "
                    +   problem.getClassName()
                    +   "())."
                    +   problem.getMethodName()
                    +   "(");
                }
                for (int j= 0; j != pt.length; j++) {
                    if (j != 0) {
                        buf.append(", ");
                    }
                    genValueRef(buf, pt[j], vals[j], lang, pn[j]);
                }
                buf.append("),");
                genValueRef(buf, problem.getReturnType(), tests[i].getOutput(), lang, RETVAL );
                buf.append(");" );
                if ( needDef( lang ) ) {
                    buf.append( indent(lang) + "\n    }" );
                }
                if (i != tests.length - 1) {
                    buf.append("\n");
                }
            }
        }
        tags.put(MAINBODY, buf.toString());
        return "";
    }
    /**
     * Generates an in-place value aggregate. 
     * @param buf The buffer to which to append the resulting declaration
     * @param dt The data type of the parameter
     * @param val the value of the parameter
     * @param lang the target language
     */
    private static void genValue( StringBuffer buf, DataType dt, String val, Language lang ) {
        if ( dt.getBaseName().toLowerCase().indexOf("long") != -1 ) {
            val= val.replaceAll("\\d+", "$0L");
        }
        if (dt.getDimension() != 0) {
            val= val.replaceAll("\n", "\n           "+indent(lang) );
        }
        buf.append(val);
    }
    /**
     * Generates a value reference or an in-place value aggregate for languages
     * that support such aggregates. 
     * @param buf The buffer to which to append the resulting declaration
     * @param dt The data type of the parameter
     * @param val the value of the parameter
     * @param lang the target language
     * @name name of the variable to reference, if any
     */
    private static void genValueRef(StringBuffer buf, DataType dt, String val, Language lang, String name ) {
        if ( inPlace( dt, lang ) ) {
            if (dt.getDimension() != 0) {
                buf.append("new ");
                buf.append(dt.getDescriptor(lang));
                buf.append(" ");
            }
            genValue( buf, dt, val, lang );
        } else {
            if ( !empty( val ) ) {
                buf.append( name );
            } else {
                buf.append(dt.getDescriptor(lang)+"()");
            }
        }
    }
    /**
     * 
     * @param buf
     * @param dt
     * @param val
     * @param lang
     * @param name
     */
    private static void genValueDef( StringBuffer buf, DataType dt, String val, Language lang, String name ) {
        if ( !inPlace( dt, lang ) && !empty( val ) ) {
            buf.append( indent(lang)+"        "+
                dt.getBaseName().toLowerCase()+" "+name+"ARRAY[] = "
            );
            genValue( buf, dt, val, lang );
            buf.append(";\n");
            buf.append( indent(lang)+"        "+
                dt.getDescriptor(lang)+" "+name+"( "+name+"ARRAY, "+name+"ARRAY+ARRSIZE("+name+"ARRAY) );\n"
            );
        }
    }
    private static boolean needDef( Language lang ) {
        return lang.getName().equals("C++");
    }
    /**
     * 
     * @param dt
     * @param lang
     * @return
     */
    private static boolean inPlace(DataType dt,  Language lang ) {
        return (dt.getDimension() == 0) || !needDef( lang );
    }
    /**
     * 
     * @param lang
     * @return
     */
    private static String indent( Language lang ) {
        if ( lang.getName().equals("C++") ) {
            return "";
        } else {
            return "    ";
        }
    }
    private static boolean empty( String s ) {
        return s.matches("[{][\t \n\r]*[}]");
    }
    /**
     * 
     * @param lang
     * @param src
     * @return
     */
    private static boolean sameLanguage( Language lang, String src ) {
        if ( lang.getName().equals("C++") ) {
            return src.indexOf("#include") != -1;
        } else if ( lang.getName().equals("Java") ) {
            return src.indexOf("import ") != -1;
        } else if ( lang.getName().equals("C#") ) {
            return src.indexOf("using ") != -1 && src.indexOf("#include") == -1;
        } else {
            return true;
        }
    }
    /** List of the supported languages */
    private static final String[] supported = new String[] { "Java", "C#", "C++" };
    /** This map stores user-defined tags */
    private final Map tags= new HashMap();
    /** Name of the Writer Code tag in the code template.*/
    private static final String WRITERCODE= "$WRITERCODE$";
    /** Name of the Main Body tag in the code template. */
    private static final String MAINBODY= "$MAINBODY$";
    private static final String RETVAL= "retrunValue";
}
