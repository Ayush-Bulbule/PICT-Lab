/*
 Practical No 10: MongoDB Aggregation and Indexing: Design and Develop MongoDB Queries using aggregation and
 indexing with suitable example using MongoDB

 Schema:
 {
    "product":"Toothbrush",
    "total":4.6,
    "customer":"Ayush"
 }

 Queries to solve:
    1.Find out how many toothbrushes were sold
    2.Find the list of all sold products
    3.Find the total amount of money spent by each customer
    4.Find how much has been spent on each product and sort it by amount spent
    5.Find the product with least earnings.
    6.Find how much money each customer has spent on toothbrushes and pizza
    7.Find the customer who has given highest business for the product toothbrush

 */


// 1. Insert the Documents in the Database:
db.purchase_orders.insertMany([
    {
        "product": "toothbrush",
        "price": 21,
        "customer": "Ayush"
    },
    {
        "product": "milk",
        "price": 32,
        "customer": "Karan"
    },
    {
        "product": "pizza",
        "price": 139,
        "customer": "Kushal"
    },
    {
        "product": "toothbrush",
        "price": 21,
        "customer": "Ajey"
    },
    {
        "product": "pizza",
        "price": 139,
        "customer": "Kumar"
    },
    {
        "product": "milk",
        "price": 32,
        "customer": "Tanay"
    },
    {
        "product": "chocolate",
        "price": 80,
        "customer": "Piyush"
    },
]);


//1. Find out how many toothbrushes were sold
//Single Aggregation
db.purchase_orders.count({ product: 'toothbrush' });
//OR
db.purchase_orders.aggregate([
    {
        $match: { product: 'toothbrush' }
    },
    {
        $group: {
            _id: "$product",
            totalQty: { $sum: 1 }
        }
    }
]);

//2. Find the list of all products sold
db.purchase_orders.distinct("product");
//OR
db.purchase_orders.aggregate([
    {
        $group: {
            _id: "$product"
        }
    }
]);


//3. Find the total amount of money spent by each customer
db.purchase_orders.aggregate([
    {
        $group: {
            _id: "$customer",
            totalSpending: { $sum: "$price" }
        }
    }
])

// 4.Find how much has been spent on each product and sort it by amount spent

db.purchase_orders.aggregate([
    {
        $group: {
            _id: "$product",
            totalSpent: { $sum: "$price" }
        }
    },
    {
        $sort: {
            totalSpent: -1
        }
    }
])

// 5.Find the product with least earnings.
db.purchase_orders.aggregate([
    {
        $group: {
            _id: "$product",
            earnings: { $sum: "$price" }
        }
    },
    {
        $sort: {
            price: -1
        }
    },
    {
        $limit: 1
    }
])

// 6.Find how much money each customer has spent on toothbrushes and pizza

db.purchase_orders.aggregate([
    {
        $match: { product: { $in: ['toothbrush', 'pizza'] } }
    },
    {
        $group: {
            _id: "$customer",
            spending: { $sum: "$price" }
        }
    }
])


// 7.Find the customer who has given highest business for the product toothbrush
db.purchase_orders.aggregate([
    {
        $match: { product: 'toothbrush' }
    },
    {
        $group: {
            _id: "$customer",
            bussiness: { $sum: "$price" }
        }
    },
    {
        $sort: { bussiness: -1 }
    },
    {
        $limit: 1
    }
])