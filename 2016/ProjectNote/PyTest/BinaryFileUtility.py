def tohex(val, nbits):# solve the negative number representation problem
 return hex((val + (1 << nbits)) % (1 << nbits))
def _unescape_entities(text):
    """
    unescape offending tags < > " &
    """
    text = text.replace(b'&lt;', b'<')
    text = text.replace(b'&gt;', b'>')
    text = text.replace(b'&quot;', b'"')
    text = text.replace(b'&amp;', b'&')
    return text
