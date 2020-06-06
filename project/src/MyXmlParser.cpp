/*************************************************************************
* ADOBE SYSTEMS INCORPORATED
* Copyright 2013 Adobe Systems Incorporated
* All Rights Reserved.

* NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance with the
* terms of the Adobe license agreement accompanying it.  If you have received this file from a
* source other than Adobe, then your use, modification, or distribution of it requires the prior
* written permission of Adobe.
**************************************************************************/

#include "MyXmlParser.h"
#include "IFCMStringUtils.h"
#include "Utils.h"
#include "DocType.h"
#include <map>

namespace CreateJS
{
    typedef std::pair <std::string, std::string> Pair_Attrib;

    FeatureDocumentHandler::FeatureDocumentHandler(CreateJS::FeatureMatrix *pFeatureMat) : 
        DocumentHandler(), 
        m_pFeatureMat(pFeatureMat)
    {
    }


    void FeatureDocumentHandler::startElement(const XMLCh* const name, AttributeList& attrs)
    {
        char elementName[1024];

        XMLString::transcode(name, elementName, 1024 - 1);
        std::string elemName(elementName);
        std::map<std::string, std::string> attributes;
        
        for (unsigned int c = 0; c < attrs.getLength() ; c++) 
        {
            char attributeName[1024];
            char attributeValue [1024];
            XMLString::transcode(attrs.getName(c), attributeName, 1024 - 1);
            XMLString::transcode(attrs.getValue(c), attributeValue, 1024 - 1);
            std::string attribName(attributeName);
            std::string attribVal(attributeValue);

            attributes.insert(Pair_Attrib(attribName, attribVal));
        }
        m_pFeatureMat->StartElement(elemName, attributes);
    }
    
    void FeatureDocumentHandler::endElement(const XMLCh* const name)
    {
        char elementName[1024];
        XMLString::transcode(name, elementName, 1024 - 1);
        std::string elemName(elementName);
        m_pFeatureMat->EndElement(elemName);
    }

};
