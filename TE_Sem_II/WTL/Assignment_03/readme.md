## Assignment 03 - XML

### Questions

1. What is XML? What is it used for? <br/>
    Ans: XML (eXtensible Markup Language) is a versatile markup language used for structuring and storing data in a hierarchical format. Its need arises from the requirement to exchange data between incompatible systems in a platform-independent and self-descriptive manner. XML provides a standardized format for representing structured data, making it easier to share and interpret information across different applications and platforms. It's commonly used in web services, data interchange, configuration files, and document storage, facilitating interoperability and data exchange between diverse systems.

2. What are the strengths of XML technology? <br/>
    Ans: XML technology offers several strengths, including:
        - Structured Data Representation: XML provides a structured format for representing data, making it easy to organize and understand complex information.
        - Platform Independence: XML documents can be processed on any platform or operating system, ensuring interoperability across diverse environments.
        - Self-Descriptive: XML documents are self-descriptive, containing both data and metadata, which aids in data interpretation and processing.
        - Extensibility: XML allows users to define custom markup languages and extend existing vocabularies, providing flexibility in data modeling.
        - Standardization: XML is a widely adopted standard, supported by numerous tools, libraries, and technologies for parsing, validation, and transformation.

3. What are DTDs? How do they work? <br/>
    Ans: DTDs (Document Type Definitions) are a type of schema used to define the structure, elements, and attributes of an XML document. They specify the rules and constraints that govern the content and organization of XML documents within a particular document type. DTDs work by providing a formal grammar for validating XML documents against predefined rules. They define the element types, their nesting relationships, allowed attributes, and entity references, ensuring the consistency and integrity of XML data.
    Example: How to define a simple DTD for an XML document that describes books:
        ```xml
            <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
                "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

            <!ELEMENT employees (employee*)>
            <!ELEMENT employee (id, name, department, position, salary)>
            <!ELEMENT id (#PCDATA)>
            <!ELEMENT name (#PCDATA)>
            <!ELEMENT department (#PCDATA)>
            <!ELEMENT position (#PCDATA)>
            <!ELEMENT salary (#PCDATA)>
        ```

4. What is the difference between well-formed and valid XML documents? <br/>
    Ans: The difference between well-formed and valid XML documents is as follows:
        - Well-Formed XML Document: A well-formed XML document adheres to the basic syntax rules of XML, such as having a single root element, properly nested elements, and correct attribute quoting. It must also include a declaration at the beginning of the document. A well-formed XML document can be parsed and processed by XML parsers.
        - Valid XML Document: A valid XML document is not only well-formed but also conforms to a specific schema or Document Type Definition (DTD) or XML Schema. It must satisfy the rules and constraints defined in the schema, such as element structure, data types, and content models. Validation ensures that the XML document meets the requirements of a particular document type.

5. Explain the differences between external and internal DTDs. <br/>
    Ans: Differences
     - External DTD: An external DTD is a separate file that defines the structure and rules of an XML document. It's referenced within the XML document using a DOCTYPE declaration, which specifies the location of the external DTD file.
     Internal DTD: An internal DTD is defined within the XML document itself, typically in the document's prologue before the root element. It's enclosed within square brackets [] and contains the document type declaration directly within the XML file.

6. What are XML schemas? How are they better than DTDs? <br/>
    Ans: XML schemas are an alternative to DTDs for defining the structure, constraints, and data types of XML documents. They are written in XML syntax and provide more expressive power and flexibility compared to DTDs. XML schemas support data typing, namespaces, and more sophisticated validation rules. Unlike DTDs, XML schemas are themselves XML documents, making them easier to understand, manipulate, and process. Additionally, XML schemas offer better support for data validation, interoperability, and extensibility, making them preferred over DTDs in many scenarios.

7. Explain the XSLT technology with an example. <br/>
    Ans: XSLT (eXtensible Stylesheet Language Transformations) is a language for transforming XML documents into other formats, such as HTML, XHTML, or plain text. It's commonly used to convert XML data into a presentation format suitable for display in web browsers or other applications. Here's a simple example of an XSLT transformation:
        ```xml
            <!-- XML Source Document -->
            <students>
                <student>
                    <name>John Doe</name>
                    <grade>A</grade>
                </student>
                <student>
                    <name>Jane Smith</name>
                    <grade>B</grade>
                </student>
            </students>
        ```
        ```xml
            <!-- XSLT Stylesheet -->
            <xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
                <xsl:template match="/">
                    <html>
                        <body>
                            <h2>Student Grades</h2>
                            <ul>
                                <xsl:for-each select="students/student">
                                    <li><xsl:value-of select="name"/> - <xsl:value-of select="grade"/></li>
                                </xsl:for-each>
                            </ul>
                        </body>
                    </html>
                </xsl:template>
            </xsl:stylesheet>
        ```
        This XSLT stylesheet transforms the XML source document into an HTML list of student names and grades.
