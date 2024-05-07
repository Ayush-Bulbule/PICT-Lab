/* 
Design a login page with entries for name, mobile number email id and
login button. Use struts and perform following validations
Validation for correct names
Validation for mobile numbers
Validation for email id
Validation if no entered any value
Re-display for wrongly entered values with message
Con ratulations and welcome a e u on successful entries

code for deomonstrating the above is as follows (NOT Tested**)
*/

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Assignment_8 extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String name = request.getParameter("name");
        String mobile = request.getParameter("mobile");
        String email = request.getParameter("email");
        String submit = request.getParameter("submit");
        if (submit != null) {
            if (name.equals("") || mobile.equals("") || email.equals("")) {
                out.println("Please fill all the fields");
            } else {
                Pattern pattern = Pattern.compile("^[a-zA-Z]*$");
                Matcher matcher = pattern.matcher(name);
                if (matcher.matches()) {
                    pattern = Pattern.compile("^[0-9]*$");
                    matcher = pattern.matcher(mobile);
                    if (matcher.matches()) {
                        pattern = Pattern.compile("^[a-zA-Z0-9]*@[a-zA-Z]*.[a-zA-Z]*$");
                        matcher = pattern.matcher(email);
                        if (matcher.matches()) {
                            out.println("Congratulations and welcome " + name + " on successful entries");
                        } else {
                            out.println("Please enter a valid email id");
                        }
                    } else {
                        out.println("Please enter a valid mobile number");
                    }
                } else {
                    out.println("Please enter a valid name");
                }
            }
        }
    }
}