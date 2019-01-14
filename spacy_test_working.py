import spacy, functions

sentence = functions.get_data('text.txt')
# list = functions.get_data('data.csv')


nlp = spacy.load('fr')
doc = nlp(sentence)
functions.get_sentences(doc)

# keke = functions.sentiment_analyse(doc, list, sentence)
# print("tn ga lo c 1 vré! il é a", keke) 