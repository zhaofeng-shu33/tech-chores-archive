<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="text">
<html>
	<head>
		<meta charset="utf-8"/>
		<title></title>
	</head>
	<body>
	<table width="70%" border="0" bgcolor="#047DB1">
	<tr>
	<td><span style="color: #FFFFFF;">
	<font size="15"><b><xsl:value-of select="head"/>&#160;<xsl:value-of select="title"/></b></font></span></td></tr></table>
	<xsl:for-each select="body/div">
		<br/>

	<xsl:choose>
		<xsl:when test="child::p">
		<xsl:for-each select="p">
	<xsl:for-each select="s">
	<a>
	<xsl:attribute name="title"><xsl:value-of select="te"/></xsl:attribute>
	
	<font size="5"><xsl:value-of select="or"/></font></a>&#160;
	</xsl:for-each>	
	<br/>
	</xsl:for-each>
	</xsl:when>
	<xsl:otherwise>
	<xsl:for-each select="sp">
	<xsl:choose>
		<xsl:when test="contains(@who,'Frau')">
		<span style=";background-color:#aaaaaa; font-size:25px;">&#160;&#160;&#160;&#160;&#160;<xsl:value-of select="@who"/><xsl:text>:</xsl:text></span>	
		</xsl:when>
	<xsl:otherwise>
		<span style=";background-color:#0da2c1; font-size:25px;"><xsl:value-of select="@who"/><xsl:text>:</xsl:text></span>	
	</xsl:otherwise>
	</xsl:choose>
	
	<xsl:for-each select="s">&#160;
	<a>
	<xsl:attribute name="title"><xsl:value-of select="te"/></xsl:attribute>
	
	<font size="5"><xsl:value-of select="or"/></font></a>
	
	</xsl:for-each>	
	<br/>
	</xsl:for-each>
	<br/>	
	</xsl:otherwise>
	</xsl:choose>
	
	</xsl:for-each>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>