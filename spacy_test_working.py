import spacy, functions

list = []

bloc = functions.get_data('text.txt')
nlp = spacy.load('fr')
doc = nlp(bloc)
list, nb_sents = functions.get_sentences(doc)
# print ('[',nb_sents,']')
# for i in range(0, nb_sents):
#     print (i, list[i])
for token in list[0]:
    print("{0}\t{1}".format(token.text,token.tag_))