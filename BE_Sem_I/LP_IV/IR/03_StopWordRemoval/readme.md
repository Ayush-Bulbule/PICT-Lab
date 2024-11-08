## **03Text Pre-processing - Tokenization**

### **Problem Statement**
Implement a program to tokenize a text document into individual words or phrases.

### **Objective**
- Understand the concept of tokenization in text pre-processing.
- Learn how tokenization breaks text into meaningful components (tokens) for further processing.

### **Outcome**
- Tokenize text into words or sub-phrases for subsequent analysis.
- Gain hands-on experience with tokenization using NLP tools.

### **Software and Hardware Used**
- **OS**: 64-bit Ubuntu  
- **RAM**: 8GB (Recommended)  
- **Tools**: Jupyter Notebook  
- **Language**: Python  

### **References**
1. A. D. Lewis, *Text Mining with R*, 2016  
2. D. Jurafsky and J. Martin, *Speech and Language Processing*, Pearson, 2020  
3. J. A. Thomas, *Text Mining: Applications and Theory*, Wiley, 2020  

### **Theory**

#### **Text Pre-processing**  
Text pre-processing is a crucial step in preparing raw text data for machine learning models. This involves converting unstructured text into a structured format that can be easily analyzed by algorithms. Key techniques include:
1. **Tokenization**  
2. **Stop Word Removal**  
3. **Lemmatization**  
4. **Stemming**  
5. **Part-of-Speech Tagging**

#### **Tokenization**  
Tokenization is the process of splitting text into individual units called tokens. Tokens are typically words, sub-phrases, or sentences and serve as the smallest units of meaning in a text. Tokenization helps break down complex text data into manageable and meaningful parts for analysis, feature extraction, or model training.

#### **Stop Word Removal**  
Stop words are common, non-informative words (e.g., "is," "the," "and") that are often removed during text preprocessing. Removing these words helps focus on more meaningful content and reduces noise in the data, allowing models to better identify patterns related to the core content.

#### **Lemmatization**  
Lemmatization reduces words to their base or root forms, known as *lemmas*, by considering the word’s meaning and part of speech. For example, "running" is lemmatized to "run". This process ensures that words with similar meanings are treated as the same entity, improving consistency in the data.

#### **Stemming**  
Stemming simplifies words by removing suffixes to yield the word root. For instance, "running" is stemmed to "run". Unlike lemmatization, stemming does not consider a word’s context or part of speech, so it may result in root words that aren't real words. However, it reduces data dimensionality and can speed up processing.

#### **Part-of-Speech (POS) Tagging**  
POS tagging assigns labels to each word based on its part of speech (e.g., noun, verb, adjective). This adds syntactic information, which can help in understanding the grammatical structure of sentences and improving the accuracy of text processing applications.

### **Algorithm**

1. Input the raw text document.
2. Use a tokenizer to break down the text into tokens (words or phrases).
3. Return the list of tokens.
4. Print the tokenized text for further processing.


```python
# Importing the necessary library
import nltk
from nltk.tokenize import word_tokenize

# Download required NLTK data files (only the first time)
nltk.download('punkt')

# Define the text to be tokenized
text = "This is an example sentence. Tokenize this text into words."

# Tokenize the text into words
tokens = word_tokenize(text)

# Display the tokenized words
print("Tokens:", tokens)


```

### **Test Cases**

1. **Input**: `"This is an example sentence."`  
   **Output**: `['This', 'is', 'an', 'example', 'sentence']`

2. **Input**: `"Tokenize this text into words."`  
   **Output**: `['Tokenize', 'this', 'text', 'into', 'words']`

### **Conclusion/Analysis**
Tokenization was implemented successfully, demonstrating its effectiveness in breaking down raw text for further pre-processing tasks such as stop word removal, stemming, and sentiment analysis.
