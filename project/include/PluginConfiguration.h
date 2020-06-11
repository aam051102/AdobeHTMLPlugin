/*************************************************************************
* ADOBE SYSTEMS INCORPORATED
* Copyright 2014 Adobe Systems Incorporated
* All Rights Reserved.

* NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance with the
* terms of the Adobe license agreement accompanying it.  If you have received this file from a
* source other than Adobe, then your use, modification, or distribution of it requires the prior
* written permission of Adobe.
**************************************************************************/


/*
 * PLUGIN DEVELOPERS MUST CHANGE VALUES OF ALL THE MACROS AND CONSTANTS IN THIS FILE 
 * IN ORDER TO AVOID ANY CLASH WITH OTHER PLUGINS.
 */


#ifndef _PLUGIN_CONFIGURATION_H_
#define _PLUGIN_CONFIGURATION_H_

#define PUBLISHER_NAME						"MadCreativity"
#define PUBLISHER_UNIVERSAL_NAME			"com.mad.MadCreativity"

/* The value of the PUBLISH_SETTINGS_UI_ID has to be the HTML extension ID used for Publish settings dialog*/
#define PUBLISH_SETTINGS_UI_ID				"com.mad.AnimeJS.PublishSettings"

#define DOCTYPE_NAME						"AnimeJS"
#define DOCTYPE_UNIVERSAL_NAME				"com.mad.AnimeJS"
#define DOCTYPE_DESCRIPTION					"Export to AnimeJS for better browser support"

/* The value of RUNTIME_FOLDER_NAME must be the name of the runtime folder present in EclipseProject/ExtensionContent. */
#define RUNTIME_FOLDER_NAME                 "Runtime"

namespace AnimeJS
{
    // {1cfc532d-a95b-4a33-b4c8-92fe85a8c9b3}
    const FCM::FCMCLSID CLSID_DocType =
        {0x1cfc532d, 0xa95b, 0x4a33, {0xb4, 0xc8, 0x92, 0xfe, 0x85, 0xa8, 0xc9, 0xb3}};

    // {e896c060-4e09-4ebe-a88f-e02c30c98207}
    const FCM::FCMCLSID CLSID_FeatureMatrix =
        {0xe896c060, 0x4e09, 0x4ebe, {0xa8, 0x8f, 0xe0, 0x2c, 0x30, 0xc9, 0x82, 0x07}};

	// {783657c4-96b1-4c7b-84d8-9e1247ebdeaf}
    const FCM::FCMCLSID CLSID_Publisher =
        {0x783657c4, 0x96b1, 0x4c7b, {0x84, 0xd8, 0x9e, 0x12, 0x47, 0xeb, 0xde, 0xaf}};


    // {a6d6d58d-916f-4df6-bbee-87f77407e2cb}
    const FCM::FCMCLSID CLSID_ResourcePalette =
        {0xa6d6d58d, 0x916f, 0x4df6, {0xb, 0xee, 0x87, 0xf7, 0x74, 0x07, 0xe2, 0xcb}};

    // {91b82373-74bf-4efd-9fe8-e6b6dd2ab677}
    const FCM::FCMCLSID CLSID_TimelineBuilder =
        {0x91b82373, 0x74bf, 0x4efd, {0x9f, 0xe8, 0xe6, 0xb6, 0xdd, 0x2a, 0xb6, 0x77}};

    // {3e6de25b-84b1-433c-a044-70245d846136}
    const FCM::FCMCLSID CLSID_TimelineBuilderFactory =
        {0x3e6de25b, 0x84b1, 0x433c, {0xa0, 0x44, 0x70, 0x24, 0x5d, 0x84, 0x61, 0x36}};
}


#endif // _PLUGIN_CONFIGURATION_H_