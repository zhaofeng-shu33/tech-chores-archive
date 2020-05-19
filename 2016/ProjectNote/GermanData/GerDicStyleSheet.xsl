<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
<xsl:output method="html" version="3.2"/>
	<xsl:template match="//Chinesisch" xml:space="default">
		<HTML>
			<HEAD>
				<TITLE>
					<xsl:text>Basic German Word List</xsl:text>
				</TITLE>
			</HEAD>
			<BODY BGCOLOR="#ffffff">
			<!--255,255,255 represents white color-->
			<p><xsl:value-of select="@TE"/></p>
			</BODY>
		</HTML>
	</xsl:template>
	
</xsl:stylesheet>
