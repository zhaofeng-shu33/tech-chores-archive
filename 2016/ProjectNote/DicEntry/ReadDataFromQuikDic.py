f=open('D:\Deutsch Unterricht\Quickdic\Lessons\Examples\\Computer.ger')
a=f.read()
a=a.decode('ISO-8859-2')
#decode: convert from other coding to unicode
#encode convert from unicode to othercode.
print a
