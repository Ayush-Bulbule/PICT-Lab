import re
import math
from sklearn.feature_extraction.text import ENGLISH_STOP_WORDS

# Function to read and preprocess text
def read_and_preprocess(text):
    # Tokenizing into words, converting to lowercase, and removing punctuation
    words = re.findall(r'\b\w+\b', text.lower())
    # Removing stop words
    filtered_words = [word for word in words if word not in ENGLISH_STOP_WORDS]
    return filtered_words

# Function to count word frequency
def word_frequency(words):
    freq = {}
    for word in words:
        freq[word] = freq.get(word, 0) + 1
    return freq

# Function to compute cosine similarity
def compute_cosine_similarity(query, document):
    # Preprocessing
    query_words = read_and_preprocess(query)
    document_words = read_and_preprocess(document)
    
    # Counting word frequencies
    query_freq = word_frequency(query_words)
    doc_freq = word_frequency(document_words)
    
    # Finding unique words for vector space
    all_words = set(query_freq.keys()).union(set(doc_freq.keys()))
    
    # Creating vectors
    query_vector = [query_freq.get(word, 0) for word in all_words]
    doc_vector = [doc_freq.get(word, 0) for word in all_words]
    
    # Calculating dot product and magnitudes
    dot_product = sum(q * d for q, d in zip(query_vector, doc_vector))
    magnitude_query = math.sqrt(sum(q ** 2 for q in query_vector))
    magnitude_doc = math.sqrt(sum(d ** 2 for d in doc_vector))
    
    # Calculating cosine similarity
    if magnitude_query == 0 or magnitude_doc == 0:
        return 0  # Avoid division by zero
    cosine_similarity = dot_product / (magnitude_query * magnitude_doc)
    
    # Angle in degrees (optional)
    angle = math.degrees(math.acos(cosine_similarity))
    
    return cosine_similarity, angle

# Example Usage
query = "Sample text of the query document"
document = "Text content of the main document to compare"
similarity_score, angle = compute_cosine_similarity(query, document)
print("Cosine Similarity:", similarity_score)
print("Angle (in degrees):", angle)
