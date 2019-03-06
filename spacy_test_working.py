import functions
# import spacy

analyse = []

result_contenaire, result_profil = functions.get_result_csv('Vigiscrap/res/result.csv')
keywords = functions.get_keywords('keywords.csv')
analyse = functions.get_bad_sentence(result_contenaire, keywords, analyse)

functions.print_analyse(analyse)

# nlp = spacy.load('fr')

# text = open('Vigiscrap/res/result.csv', 'r').read()
# doc = nlp(text)
# for token in doc:
#     print (token.text, token.tag_)


# result_contenaire = functions.put_spacy_on_list(result_contenaire)



# doc = nlp(result_contenaire)
# print (doc)




# for row in keywords:
#     print (row[0])
# print (result_contenaire)
# print (result_profil)
# print (", ".join(result_profil[0]))
# print (len(result_contenaire[1]))
# j = 2
# for i in range(1,len(result_contenaire)):
#     print (str(i)+" |"+result_contenaire[i][j]+"|", result_contenaire[i][0], result_contenaire[i][1])
# print (result_contenaire[0][j])


# for row in keywords:
#     print (row)
# list, nb_sents = functions.get_sentences(doc)


# print ('[',nb_sents,']')
# for i in range(0, nb_sents):
#     print (i, list[i])


# for token in list[0]:
#     print("{0}\t{1}".format(token.text,token.tag_))