/*
 * Praactical No: 8 Database Connectivity:
 * Write a program to implement MySQL/Oracle database connectivity with any front end 
 * language to implement Database navigation operations (add, delete, edit etc.)
 * 
 * Steps to connect the MYSQL:
 *  1. Download Mysql Jar https://dev.mysql.com/downloads/connector/j/ (select platform independant .zip)
 *  2. Extract anywhere.
 *  3. Create new Project>Java Project in ecllipse
 *  4. Create new .class to the java project
 *  5. Project> Properties> Libraries> ModulePath > External Jar> 
 *  6. Locate and Select your extracted .jar file.
 *  7. Write your code and execute it!
 */
import java.sql.*;

public class Assignment8 {
	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			
			Connection con = DriverManager.getConnection(
					"jdbc:mysql://localhost:3307/practice",
					"root",
					"Ayush2413"
					);
			
			PreparedStatement ps = null;
			ps = con.prepareStatement("select * from users");
			
			ResultSet rs = ps.executeQuery();
			
			System.out.println(rs);				
			System.out.println("ID\tusername\temail\tage");
			while(rs.next()) {
				int id = rs.getInt(1);
				String username = rs.getString(2);
				String email = rs.getString(3);
				int age = rs.getInt(4);	
				System.out.println(id+"\t"+username+"\t"+email+"\t"+age);
			}
			
			insert(ps,con);
			update(ps,con);
			display(ps,con);
		}catch(Exception ex) {
			ex.printStackTrace();
		}		
	}
	
	public static void display(PreparedStatement ps, Connection con) {
		try {
			ps = con.prepareStatement("SELECT * FROM users");
			
			ResultSet rs = ps.executeQuery();
			
			System.out.println("ID\tusername\temail\tage");
			while(rs.next()) {
				int id = rs.getInt(1);
				String username = rs.getString(2);
				String email = rs.getString(3);
				int age = rs.getInt(4);
				System.out.println(id+"\t"+username+"\t"+email+"\t"+age);
			}
		}catch(Exception ex) {
			ex.printStackTrace();
		}
	}
	
	public static void insert(PreparedStatement ps, Connection con) {
		try {
			ps = con.prepareStatement("INSERT INTO users(username,email,age) values(?,?,?)");
			
			ps.setString(1, "tanay12");
			ps.setString(2, "tanay@gmail.com");
			ps.setInt(3, 20);
			ps.executeUpdate();
		}catch(Exception ex) {	
			ex.printStackTrace();
		}
	}
	
	public static void update(PreparedStatement ps, Connection con) {
		try {
			ps = con.prepareStatement("UPDATE users SET email=? WHERE id=?");
			ps.setString(1,"sample2@gmail.com");
			ps.setInt(2, 3);
			ps.executeUpdate();			
		}catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}
