/**
 * Problem Statement: Implement the sample program demonstrating the use of Servlet. 
 * e.g., Create a database table ebookshop (book_id, book_title, book_author,book_price, quantity) 
 * using database like Oracle/MySQL etc. and display(use SQL select ue ) the table content usin servlet.
 */


import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Assignment05 extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>Assignment 05</title></head><body>");
        out.println("<h1>Assignment 05</h1>");
        out.println("<h2>Displaying ebookshop table</h2>");
        out.println("<table border='1'>");
        out.println("<tr><th>Book ID</th><th>Book Title</th><th>Book Author</th><th>Book Price</th><th>Quantity</th></tr>");
       
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ebookshop", "root", "");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM ebookshop");
            while (rs.next()) {
                out.println("<tr>");
                out.println("<td>" + rs.getInt("book_id") + "</td>");
                out.println("<td>" + rs.getString("book_title") + "</td>");
                out.println("<td>" + rs.getString("book_author") + "</td>");
                out.println("<td>" + rs.getDouble("book_price") + "</td>");
                out.println("<td>" + rs.getInt("quantity") + "</td>");
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

