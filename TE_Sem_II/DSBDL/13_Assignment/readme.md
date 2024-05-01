#### Assignment No 13

**Aim**: Write a simple program in SCALA using Apache Spark framework

**Objective**: To understand how to write a simple program in SCALA using Apache Spark framework

**Prerequisites**:
- Apache Spark
- SCALA

**Procedure**:
1. Install Apache Spark and SCALA
2. Create a new SCALA program

    ```scala
        // This opens up an interactive shell
        // Create a new input1.txt file

        val input = sc.textFile("input1.txt")

        // Create a new RDD by splitting the input RDD on the basis of space
        val words = input.flatMap(x => x.split(" "))

        // Create a new RDD by mapping each word to a tuple of (word, 1)
        val counts = words.map(x => (x, 1))

        // Create a new RDD by reducing the tuples by key
        val reducedCounts = counts.reduceByKey((x, y) => x + y)

        // Save the RDD to a file
        reducedCounts.saveAsTextFile("output1.txt")

        // Print the contents of the file
        reducedCounts.foreach(println) 
    ```

    Save the file as `wordcount.scala`
3. Compile and run the program
    
        ```bash
            $ ./spark-shell
            scala> :load wordcount.scala
        ```
4. Observe the output

**Output**:
- The output will be saved in the `output1.txt` file

**Result**:
- A simple program in SCALA using Apache Spark framework was written and executed successfully
