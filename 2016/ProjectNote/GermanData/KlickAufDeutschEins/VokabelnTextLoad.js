
	
		document.write("<table border='1' align='center'>")
		
		var xmlDom=new ActiveXObject("MSXML2.DOMDocument.4.0");
		xmlDom.async="false";
		xmlDom.load("VokabelnText.xml");
		var xmlObj=xmlDom.documentElement.childNodes;//xmlObj is wordGroups
		for(j=0;j<xmlObj.length;j++){
    		var wordNodeList=xmlObj.item(j).childNodes;//wordNodeList is several words
    		for(var i=0;i<wordNodeList.length-1;i++){	
    		var wordDetailNode=wordNodeList.item(i).firstChild;//wordform or TE
    		var PropertyInformation=wordNodeList.item(i).getAttribute("Property");
    		var wordLevel=parseInt(wordNodeList.item(i).getAttribute("Level"));
    		
    		if(wordLevel==4){
    				 document.write("<tr><td bgcolor='#c88b48'><sup>*&nbsp;&nbsp;</sup></td>");
    			}
    		else if(wordLevel==6){
    				 document.write("<tr><td bgcolor='#c88b48'><sup>#</sup></td>");
    			}		  
    		else document.write("<tr><td bgcolor='#c88b48'>&nbsp;</td>"); 
    		
    		while(wordDetailNode){
    		if(wordDetailNode.nodeName=="TE"){
    			document.write("<td bgcolor='#c88b48'style='font-family:FangSong;font-size:20px;font-weight:bold'>"+wordDetailNode.text+"</td>");
    		}
    		else{
    		var originalWordNode=wordDetailNode.selectSingleNode("or");
    		var reflectiveChangeNode=wordDetailNode.selectSingleNode("reflectiveChange");   		
    		document.write("<td ><a title='"+ reflectiveChangeNode.text+ "'>" + originalWordNode.text + "</a></td><td>"+PropertyInformation+"</td>");    		
    		}
    		wordDetailNode=wordDetailNode.nextSibling;
    		}
    		if(i==0){
    			document.write("<td rowspan='"+(wordNodeList.length-1)+"' width='200'>"+wordNodeList.item(wordNodeList.length-1).text+'</td>');
    		}
    		document.write("</tr>");
    		<!--wordNode=wordNode.nextSibling;-->
    		}
    		
	  }
	
		document.write("</table>");
		