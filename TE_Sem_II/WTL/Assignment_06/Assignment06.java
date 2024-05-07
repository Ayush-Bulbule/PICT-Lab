/**
 * Problem Statement: Implement the program demonstrating the use of JSP.
 * e.g., Create a database table students info (stud id, stud_name, class, division, city) 
 * using database like Oracle/MySQL etc. and display (use SQL select the table content usin JSP.
 * 
 */


import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Assignment06 extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>Assignment 06</title></head><body>");
        out.println("<h1>Assignment 06</h1>");
        out.println("<h2>Displaying students_info table</h2>");
        out.println("<table border='1'>");
        out.println("<tr><th>Student ID</th><th>Student Name</th><th>Class</th><th>Division</th><th>City</th></tr>");
       
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/students_info", "root", "");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM students_info");
            while (rs.next()) {
                out.println("<tr>");
                out.println("<td>" + rs.getInt("stud_id") + "</td>");
                out.println("<td>" + rs.getString("stud_name") + "</td>");
                out.println("<td>" + rs.getString("class") + "</td>");
                out.println("<td>" + rs.getString("division") + "</td>");
                out.println("<td>" + rs.getString("city") + "</td>");
                out.println("</tr>");
            }
            out.println("</table>");
            out.println("</body></html>");
            con.close();
        } catch (Exception e) {
            out.println(e);
        }
    }
}

// Command to run the servlet:
// javac -cp /path/to/tomcat/lib/servlet-api.jar Assignment06.java

// Move the generated Assignment06.class file to /path/to/tomcat/webapps/ROOT/WEB-INF/classes/

// Restart the tomcat server

// Open the browser and type the URL: http://localhost:8080/Assignment_06/Assignment06

// Output:
// Assignment 06
// Displaying students_info table
// Student ID	Student Name	Class	Division	City
// 1	Ayush B	10	A	Ahmedabad
