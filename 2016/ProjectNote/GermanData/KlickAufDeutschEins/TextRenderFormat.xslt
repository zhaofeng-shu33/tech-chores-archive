<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="text">
<html>
	<head>
		<meta charset="utf-8"/>
		<title></title>
	</head>
	<body>
	<table width="100%" border="0" bgcolor="#047DB1">
	<tr><!--
	<td><object height="20" width="35" ><xsl:attribute name="data"><xsl:value-of select="head/@audio"/></xsl:attribute>
		<param name="autostart" value="false"/></object>
	</td>
	<td><object height="20" width="35" ><xsl:attribute name="data"><xsl:value-of select="title/@audio"/></xsl:attribute>
		<param name="autostart" value="false"/></object>
	</td>-->
	<td><span style="color: #FFFFFF;">
	<font size="15"><b><xsl:value-of select="head"/>&#160;<xsl:value-of select="title"/></b></font></span></td></tr></table>
	<xsl:for-each select="body/p">
	<br/>&#160;&#160;&#160;
	<xsl:for-each select="s">&#160;
	<xsl:if test="@audio">
	<object height="20" width="35" ><xsl:attribute name="data"><xsl:value-of select="@audio"/></xsl:attribute>
		<param name="autostart" value="false"/>
	</object></xsl:if>
	<!--<img src="..\DicTest\Wort\snd_sfx.png" style="margin-bottom:0px" border="0" ></img>-->
	<a>
	<xsl:attribute name="title"><xsl:value-of select="te"/></xsl:attribute>
	
	<font size="5"><xsl:value-of select="or"/></font></a></xsl:for-each>	
	<br/>
	</xsl:for-each>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>