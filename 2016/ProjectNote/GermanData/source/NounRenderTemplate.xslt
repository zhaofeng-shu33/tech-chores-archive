<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="Eintrag">
<html>
	<head>
		<meta charset="utf-8"/>		
		<title>Enter your title here</title>
	</head>
	<body>
			<h1><b><xsl:value-of select="Stichwort"/></b></h1><br/>
	<b><font color="#0000D0"><xsl:value-of select="Genus"/>&#160;<xsl:value-of select="Stichwort"/>&#160;</font></b>
	<a href="sound://p008__001776626.spx" >
	 <img src="snd_sfx.png" style="margin-bottom:-2px" border="0" ></img>
	</a>
	 
	 
	 <b><font color="#DF0101"><i><xsl:value-of select="@category"/>&#160;</i></font></b>
	 <i>plural:</i><font color="green"><b><xsl:value-of select="Pluralform"/>&#160;</b></font> 
	 <i>genetiv:</i><font color="green"><b><xsl:value-of select="GenitivSingular"/>&#160;</b></font> 
	 <div style='display:block;background-color:#f9f4bb;'>
	 <span style="color: black;font-weight:bold;">&#160;Unit:&#160;<xsl:value-of select="Einheit"/></span>&#160;
	 
	 <span style="color: black;font-weight:bold;">&#160;Part:&#160;<xsl:value-of select="Anteil"/></span>&#160;
	 </div>
	 <xsl:for-each select="AllgemeineErläuterungen/Eintrag">
	 <table width="100%" border="0" bgcolor="#D07427"><!--width=100%表示宽度上占满整个屏幕-->
	 <tr><td><span style="color: #FFFFFF;"><b><font face="仿宋"><xsl:value-of select="Chinesisch"/></font></b></span></td></tr></table>
	 <xsl:for-each select="BeispielSammlung/Beispiel">
	 <ex><font color="#2F4F4F"><xsl:value-of select="Satz"/></font></ex><br/>
	 <ex><font color="#59C945" face="仿宋"><xsl:value-of select="Übersetzung"/></font></ex><br/>
	 </xsl:for-each>
	 </xsl:for-each>

	<xsl:if test="count(Kollokationen/K) &gt; 0">
	<table width="100%" border="0" bgcolor="#697C15">
	<tr><td><span style="color: #FFFFFF;"><b><font face="仿宋">常用搭配</font></b></span></td></tr></table>
	<font color="saddlebrown">
	<xsl:for-each select="Kollokationen/K">
	<xsl:value-of select="."/><br/>
	</xsl:for-each>
	</font>
	</xsl:if>

	<xsl:if test="(count(zusammengesetzteWörter/KompositaCollection/K_)+count(zusammengesetzteWörter/KompositaCollection/_K)) &gt; 0">	
	<table width="100%" border="0" bgcolor="#047DB1">
	<tr><td><span style="color: #FFFFFF;"><b><font face="仿宋">合成词</font></b></span></td></tr></table>
	<font color="gray">
	<!--<xsl:value-of select="count(zusammengesetzteWörter/KompositaCollection/_K)"/>-->
	<xsl:for-each select="zusammengesetzteWörter/KompositaCollection/K_">
	<xsl:value-of select="."/> &#160;&#160;
	</xsl:for-each>
	</font>
	<font color="maroon">
	<xsl:for-each select="zusammengesetzteWörter/KompositaCollection/_K">
	<xsl:value-of select="."/> &#160;&#160;
	</xsl:for-each>	
	</font>
	</xsl:if>
	
	<xsl:if test="count(zusammengesetzteWörter/abgeleiteteWörter/hierzu) &gt; 0">
    <table width="100%" border="0" bgcolor="#047DB1">
	<tr><td><span style="color: #FFFFFF;"><b><font face="仿宋">派生词</font></b></span></td></tr></table>
	<xsl:for-each select="zusammengesetzteWörter/abgeleiteteWörter/hierzu">
	<font color="saddlebrown">	
	▪<xsl:value-of select="."/>&#160;</font> <b><font color="#DF0101"><i><xsl:value-of select="@category"/></i></font></b>&#160;&#160;
	</xsl:for-each>
	</xsl:if>
	
	<xsl:if test="count(Synonymegruppe/Sym) &gt; 0">
	<table width="100%" border="0" bgcolor="#047DB1">
	<tr><td><span style="color: #FFFFFF;"><b><font face="仿宋">同义词</font></b></span></td></tr></table>
	<font color="saddlebrown">
		<xsl:for-each select="Synonymegruppe/Sym">
	▪<xsl:value-of select="."/>&#160;</xsl:for-each>
	</font>
	</xsl:if>
	
	<xsl:if test="count(Antonymegruppe/Anm) &gt; 0">
	<table width="100%" border="0" bgcolor="#047DB1">
	<tr><td><span style="color: #FFFFFF;"><b><font face="仿宋">反义词</font></b></span></td></tr></table>
	<font color="saddlebrown">
	<xsl:for-each select="Antonymegruppe/Anm">
	▪<xsl:value-of select="."/>&#160;</xsl:for-each>
	</font>
	</xsl:if>
	
	</body>
</html>
</xsl:template>
</xsl:stylesheet>