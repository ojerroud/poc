import spacy

sentence = "J'aime jouer aux billes"
nlp = spacy.load('fr')
doc = nlp(sentence)

for token in doc:
    print("{0}\t{1}\t{2}\t{3}".format(
        token.text,
        token.dep_
        token.head.text
        token.head.pos_
    ))