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

#define PUBLISHER_NAME						"SamplePlugin"
#define PUBLISHER_UNIVERSAL_NAME			"com.mad.madcreativity"

/* The value of the PUBLISH_SETTINGS_UI_ID has to be the HTML extension ID used for Publish settings dialog*/
#define PUBLISH_SETTINGS_UI_ID				"com.mad.createjs.PublishSettings"

#define DOCTYPE_NAME						"CreateJS"
#define DOCTYPE_UNIVERSAL_NAME				"com.mad.createjs"
#define DOCTYPE_DESCRIPTION					"This document can be used to author content for sample runtime"

/* The value of RUNTIME_FOLDER_NAME must be the name of the runtime folder present in EclipseProject/ExtensionContent. */
#define RUNTIME_FOLDER_NAME                 "SampleRuntime"

namespace CreateJS
{
    // {835B2A74-9646-43AD-AA86-A35F4E0ECD1B}
    const FCM::FCMCLSID CLSID_DocType =
        {0x835b2a74, 0x9646, 0x43ad, {0xaa, 0x86, 0xa3, 0x5f, 0x4e, 0xe, 0xcd, 0x1b}};

    // {50705258-F3B8-4CFF-929B-E10EC7DA8816}
    const FCM::FCMCLSID CLSID_FeatureMatrix =
        {0x50705258, 0xf3b8, 0x4cff, {0x92, 0x9b, 0xe1, 0xe, 0xc7, 0xda, 0x88, 0x16}};

	    // {1635256D-2F63-4715-BC70-6B2948CC84D5}
    const FCM::FCMCLSID CLSID_Publisher =
        {0x1635256d, 0x2f63, 0x4715, {0xbc, 0x70, 0x6b, 0x29, 0x48, 0xcc, 0x84, 0xd5}};


    // {D5830903-02D6-4133-A1F1-F272D29A1802}
    const FCM::FCMCLSID CLSID_ResourcePalette =
        {0xd5830903, 0x2d6, 0x4133, {0xa1, 0xf1, 0xf2, 0x72, 0xd2, 0x9a, 0x18, 0x2}};

    // {70E17C74-34DF-4C46-8F9D-900D2EC045E3}
    const FCM::FCMCLSID CLSID_TimelineBuilder =
        {0x70e17c74, 0x34df, 0x4c46, {0x8f, 0x9d, 0x90, 0xd, 0x2e, 0xc0, 0x45, 0xe3}};

    // {442305C9-F02F-43A4-B259-D1CC39666A94}
    const FCM::FCMCLSID CLSID_TimelineBuilderFactory =
        {0x442305c9, 0xf02f, 0x43a4, {0xb2, 0x59, 0xd1, 0xcc, 0x39, 0x66, 0x6a, 0x94}};
}


#endif // _PLUGIN_CONFIGURATION_H_