from textblob import TextBlob
from textblob_fr import PatternTagger, PatternAnalyzer

text = u"je hais"
blob = TextBlob(text, pos_tagger=PatternTagger(), analyzer=PatternAnalyzer())
# blob.tags
print(blob.sentiment)