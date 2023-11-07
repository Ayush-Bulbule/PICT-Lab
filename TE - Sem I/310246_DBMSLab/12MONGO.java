import com.mongodb.MongoClient;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.FindIterable;
import com.mongodb.client.model.Filters;
import com.mongodb.client.model.Updates;
import org.bson.Document;
import java.util.Iterator;

class Assignment12{
	public static void main(String[] args) {
		try {
			//Create connection
			MongoClient mongo = new MongoClient("localhost",27017);
			MongoDatabase db = mongo.getDatabase("pract");

			//Create collection
			db.createCollection("orders");
			MongoCollection<Document> collection = db.getCollection("orders");
			Document doc = new Document("product","book");
			doc.append("price", 220);
			doc.append("customer", "Ayush");

			//Create
			collection.insertOne(doc);
			
            //Read
			FindIterable<Document> iterDoc = collection.find();
			Iterator<Document> it = iterDoc.iterator();
			while(it.hasNext()) {
				System.out.println(it.next());
			}
			
            //Update
			collection.updateOne(Filters.eq("product","book"), Updates.set("price",240));
			//Delete 
			collection.deleteOne(Filters.eq("product","book"));
		}catch(Exception ex) {
			ex.printStackTrace();
		}
	}
}