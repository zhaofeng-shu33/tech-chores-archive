<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<!-- A basic XSL stylesheet for tinydict -->
	<!-- Christopher Manning December 2003 -->
	<xsl:output method="html" version="3.2"/>
	<xsl:template match="/" xml:space="default">
		<HTML>
			<HEAD>
				<TITLE>
					<xsl:text>Basic German Word List</xsl:text>
				</TITLE>
			</HEAD>
			<BODY BGCOLOR="#ffffff">
			<!--255,255,255 represents white color-->
			<xsl:apply-templates select="dictionary/Part"/>
			</BODY>
		</HTML>
	</xsl:template>
	
	<xsl:template match="Entry">
	<font face="Arial" color="black"><h1><xsl:apply-templates select="wordform"/></h1></font>
	 <b>meaning:</b>  <i><xsl:apply-templates select="中文翻译"/></i>
	 <br/>
	 <b>example:</b>  <i><xsl:apply-templates select="example"/></i>
	 <xsl:attribute name="bgcolor">green</xsl:attribute>
	 <br/>
	 <b>单元:</b> <i><xsl:apply-templates select="单元"/></i> 
     <b>  部分:</b> <i><xsl:apply-templates select="部分"/></i> 
	</xsl:template>
</xsl:stylesheet>
