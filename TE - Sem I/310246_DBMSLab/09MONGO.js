/** Practical NO 9:  MONGODB CRUD OPERATIONS
 * Create following MongoDB collection and insert every variety of documents: 
 * teachers ( with fields like name, qualifications, deptno, deptname,
 * designation, experience (include industry & teaching), salary (include basic,
 * TA, DA & HRA), date_of_joining, appointement_nature, area_of_expertise,
 * etc. )...add other suitable fields to certain documents.
 * 
 */


// 1.Create a database named "college" and insert one document in teachers collection.
db.teachers.insertOne({
    name: "Mr. Ajit Wagh",
    age: 27,
    qualification: ["M.Tech", "Phd"],
    deptno: 3,
    deptm_name: "ComputerEngg",
    experience: {
        industry: 5,
        teaching: 4
    },
    salary: {
        basic: 70000,
        ta: 10000,
        dra: 20000,
        hra: 30000
    },
    designation: "Professor",
    appointment_nature: "Permanent",
    area_of_expertise: ["Database", "AIML"],
    date_oj_joining: new Date("2003-02-01"),
});


// 2. Insert 3 more documents in teachers collection.
db.teachers.insertMany([
    {
        name: "Dr. Ravi Sharma",
        age: 40,
        qualification: ["PhD"],
        department: "Computer",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Artificial Intelligence", "Machine Learning"],
        date_of_joining: new Date("2005-08-15"),
        salary: {
            basic: 90000,
            ta: 15000,
            da: 25000,
            hra: 30000
        }
    },
    {
        name: "Prof. Neha Singh",
        age: 35,
        qualification: ["MTech", "PhD"],
        department: "Information Technology",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Data Science", "Cybersecurity"],
        date_of_joining: new Date("2008-04-22"),
        salary: {
            basic: 85000,
            ta: 14000,
            da: 24000,
            hra: 28000
        }
    },
    {
        name: "Dr. Anil Verma",
        age: 45,
        qualification: ["PhD"],
        department: "Electronics and Telecommunication",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Communication Systems", "Signal Processing"],
        date_of_joining: new Date("2003-02-10"),
        salary: {
            basic: 92000,
            ta: 16000,
            da: 26000,
            hra: 32000
        }
    },
    {
        name: "Prof. Priya Agarwal",
        age: 38,
        qualification: ["MTech", "PhD"],
        department: "Computer",
        designation: "Associate Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Database Systems", "Web Development"],
        date_of_joining: new Date("2006-06-17"),
        salary: {
            basic: 80000,
            ta: 13000,
            da: 22000,
            hra: 27000
        }
    },
    {
        name: "Dr. Rajesh Kapoor",
        age: 42,
        qualification: ["BTech", "MTech", "PhD"],
        department: "Information Technology",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Artificial Intelligence", "Data Analytics"],
        date_of_joining: new Date("2004-09-05"),
        salary: {
            basic: 94000,
            ta: 17000,
            da: 28000,
            hra: 33000
        }
    },
    {
        name: "Prof. Preeti Singh",
        age: 36,
        qualification: ["MTech"],
        department: "Electronics and Telecommunication",
        designation: "Assistant Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Wireless Communication", "RF Engineering"],
        date_of_joining: new Date("2009-03-12"),
        salary: {
            basic: 75000,
            ta: 12000,
            da: 20000,
            hra: 25000
        }
    },
    {
        name: "Dr. Arjun Patel",
        age: 43,
        qualification: ["PhD"],
        department: "Computer",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Machine Learning", "Natural Language Processing"],
        date_of_joining: new Date("2002-01-20"),
        salary: {
            basic: 91000,
            ta: 16000,
            da: 26000,
            hra: 31000
        }
    },
    {
        name: "Prof. Maya Gupta",
        age: 39,
        qualification: ["MTech", "PhD"],
        department: "Information Technology",
        designation: "Associate Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Cybersecurity", "Cloud Computing"],
        date_of_joining: new Date("2007-05-08"),
        salary: {
            basic: 87000,
            ta: 14000,
            da: 24000,
            hra: 29000
        }
    },
    {
        name: "Dr. Sunil Desai",
        age: 44,
        qualification: ["PhD"],
        department: "Electronics and Telecommunication",
        designation: "Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Digital Signal Processing", "Embedded Systems"],
        date_of_joining: new Date("2001-11-15"),
        salary: {
            basic: 93000,
            ta: 16000,
            da: 27000,
            hra: 32000
        }
    },
    {
        name: "Prof. Meera Joshi",
        age: 37,
        qualification: ["MTech", "PhD"],
        department: "Computer",
        designation: "Assistant Professor",
        appointment_nature: "Permanent",
        area_of_expertise: ["Web Development", "Distributed Systems"],
        date_of_joining: new Date("2010-02-25"),
        salary: {
            basic: 76000,
            ta: 13000,
            da: 22000,
            hra: 26000
        }
    }
]);

// 3. Display all documents in teachers collection.
db.teachers.find();


// 4. Find the information about all teachers of computer department 
db.teachers.find({ department: "computer" });

// 5. Find the information about all teachers of computer, IT and E&TC
db.teachers.find({ $and: [{ department: "Computer" }, { department: "IT" }, { department: "FE" }] });

// 6. Find the information about all teachers of computer, IT and E&TC
//      department having salary in between 70,000 and 1,00,000(inclusive)

db.teachers.find({ $and: [{ $or: [{ department: "Computer" }, { department: "IT" }, { department: "EXTC" }] }, { 'salary.basic': { $gt: 70000 } }, { 'salary.basic': { $lte: 100000 } }] });


// 7.  Update the experience of any teacher to 10 years and if the entry is not
//     available in database consider the entry as new entry (use update function
//     only) db.students.update({ roll: 19 }, { $set: { name: 'Rohit', course: 'IT' } }, { upsert:      true })
db.teachers.updateOne({ name: 'Prof. Meera Joshi' }, { $set: { experience: 10 } }, { upsert: true });


// 8. Find the teachers’ name and experience & arrange in decreasing order of experience
db.teachers.find().sort({ 'experience.teaching': -1 });

//8. Use save() method to insert one query to database.
db.teahers.updateOne({}, {
    $set: {
        experience: {
            teaching: 8,
            industry: 12
        }
    }
});

//9. Use update() method to change the designation of teachers whose experience
//   is 10 years or above to Professor
db.teachers.updateMany(
    { 'experience': { $gte: 10 } },
    {
        $set: {
            designation: 'Professor'
        }
    }
);


//10. delete with appointment type as adhoc
db.teachers.deleteOne

// Adding random experiences
db.teachers.find().forEach(function (teacher) {
    var randomTeachingExperience = Math.floor(Math.random() * 10) + 1; // Random number between 1 and 10
    var randomIndustryExperience = Math.floor(Math.random() * 10) + 1; // Random number between 1 and 10

    db.teachers.updateMany(
        { _id: teacher._id }, // Assuming you have an "_id" field to identify each teacher
        {
            $set: {
                experience: {
                    teaching: randomTeachingExperience,
                    industry: randomIndustryExperience
                }
            }
        }
    );
});

//Adding Appointment type

db.teachers.updateMany(
    { 'experience.teaching': { $gte: 5 } },
    { $set: { appointment_nature: "permanent" } }
);