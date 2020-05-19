<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
<xsl:template match="/">
<html>
	<head>
		<title>Test</title>
	</head>
	<body bgcolor="#f0f0f0">
    <a>
            <xsl:attribute name="href">
                <xsl:value-of select="dictionary/Entry1[2]"/>
            </xsl:attribute>
            Address
		</a>
		<xsl:element name="img">
                <xsl:attribute name="src">
                    <xsl:value-of select="dictionary/Entry1[1]"/>
                </xsl:attribute>
            </xsl:element>
	<embed height="100" width="100" src="D:/testSound.wav" autostart="false" />
	</body>
</html>
</xsl:template>
</xsl:stylesheet>
