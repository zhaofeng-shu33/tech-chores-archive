from pdfminer.pdfdocument import PDFDocument
from pdfminer.pdfparser import PDFParser
from pdfminer.pdfinterp import PDFResourceManager, PDFPageInterpreter
from pdfminer.pdfdevice import PDFDevice, TagExtractor
from pdfminer.pdfpage import PDFPage
from pdfminer.layout import LAParams
from pdfminer.converter import PDFPageAggregator
import pdfminer
import codecs
import string
f=open('D:\\ProjectNote\\GermaData\\source\\de_level_2_decrypted.pdf','rb')
parser=PDFParser(f)
document=PDFDocument(parser)
parser.set_document(document)
rsrcmgr=PDFResourceManager()
laparams=LAParams()
device=PDFPageAggregator(rsrcmgr,laparams=laparams)
interpreter=PDFPageInterpreter(rsrcmgr,device)

st1=[]
#to 42
for r in range(4,41):
    page=list(PDFPage.create_pages(document))[r]
    interpreter.process_page(page)
    layout=device.get_result()
    ls=layout._objs
    for i in ls:
            if(isinstance(i, pdfminer.layout.LTTextBoxHorizontal) and len(i.get_text())>10):
                    for j in i.get_text().split('\n'):
                            if(len(j)>2 and ord(j[len(j)-1])<50):
                                    st1.append(j)

st2=string.joinfields(st1,'\r\n')
f=codecs.open('D:\\ProjectNote\\GermaData\\Sprichwort\\zusammenZwei.txt','w','utf-8')
f.write(st2)
f.close()
