### **Assignment 2: Text Pre-processing - Tokenization**

#### **Problem Statement**
Implement a program to tokenize a text document into individual words or phrases.

#### **Objective**
- Understand the concept of tokenization in text pre-processing.
- Learn how tokenization breaks text into meaningful components (tokens) for further processing.

#### **Outcome**
- Tokenize text into words or sub-phrases for subsequent analysis.
- Gain hands-on experience with tokenization using NLP tools.

#### **Software and Hardware Used**
- **OS**: 64-bit Ubuntu  
- **RAM**: 8GB (Recommended)  
- **Tools**: Jupyter Notebook  
- **Language**: Python  

#### **References**
1. A. D. Lewis, "Text Mining with R," 2016  
2. D. Jurafsky and J. Martin, "Speech and Language Processing," Pearson, 2020  
3. J. A. Thomas, "Text Mining: Applications and Theory," Wiley, 2020  

#### **Theory**
**Text Pre-processing**:  
Pre-processing helps prepare raw text data for machine learning models. Tokenization is one of the first steps in converting unstructured text into structured formats. Common techniques include:
1. Tokenization
2. Stop word removal
3. Lemmatization
4. Stemming
5. Part-of-Speech tagging

**Tokenization**:  
Tokenization divides text into tokens, which can be words, sentences, or sub-phrases. Tokens are the smallest units of meaning in a text, useful for text analysis, feature extraction, and model training.

#### **Algorithm**
1. Input the raw text document.
2. Use a tokenizer to break down the text into tokens (words or phrases).
3. Return the list of tokens.
4. Print the tokenized text for further processing.

#### **Test Cases**
1. **Input**: "This is an example sentence."  
   **Output**: ['This', 'is', 'an', 'example', 'sentence']

2. **Input**: "Tokenize this text into words."  
   **Output**: ['Tokenize', 'this', 'text', 'into', 'words']

#### **Conclusion/Analysis**
Tokenization was implemented successfully, demonstrating its effectiveness in breaking down raw text for further pre-processing tasks such as stop word removal and sentiment analysis.

---

### **Assignment 1: Text Pre-processing - Lowercase Conversion**

#### **Problem Statement**
Implement a program to convert all characters in a text document to lowercase.

#### **Objective**
- Understand how text normalization helps in standardizing text.
- Learn to convert text to lowercase for consistency in further processing.

#### **Outcome**
- Normalize the case of all words in a document.
- Enhance text processing by eliminating case sensitivity.

#### **Software and Hardware Used**
- **OS**: 64-bit Ubuntu  
- **RAM**: 8GB (Recommended)  
- **Tools**: Jupyter Notebook  
- **Language**: Python  

#### **References**
1. A. D. Lewis, "Text Mining with R," 2016  
2. J. A. Thomas, "Text Mining: Applications and Theory," Wiley, 2020  

#### **Theory**
**Text Pre-processing**:  
Text data is often inconsistent and case-sensitive. Converting the text to lowercase ensures uniformity, making it easier to process in NLP tasks.

**Lowercase Conversion**:  
This technique ensures that all words, irrespective of their case in the original text, are treated the same. It’s essential for tasks such as sentiment analysis, where word forms (e.g., "Good" and "good") should be considered the same.

#### **Algorithm**
1. Take the raw text input.
2. Convert the entire text to lowercase.
3. Return the processed text for further use.

#### **Test Cases**
1. **Input**: "Hello World!"  
   **Output**: "hello world!"

2. **Input**: "This Is A Test."  
   **Output**: "this is a test."

#### **Conclusion/Analysis**
The lowercase conversion was implemented successfully, ensuring uniformity in the document's text for subsequent NLP tasks. This pre-processing step is essential for consistent data handling across various text analysis models.