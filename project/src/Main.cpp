/*************************************************************************
* ADOBE SYSTEMS INCORPORATED
* Copyright 2013 Adobe Systems Incorporated
* All Rights Reserved.

* NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance with the
* terms of the Adobe license agreement accompanying it.  If you have received this file from a
* source other than Adobe, then your use, modification, or distribution of it requires the prior
* written permission of Adobe.
**************************************************************************/

#include "FCMPluginInterface.h"

#include "DocType.h"
#include "Publisher.h"
#include "Utils.h"

namespace CreateJS
{
    BEGIN_MODULE(CreateJSModule)

        BEGIN_CLASS_ENTRY

            CLASS_ENTRY(CLSID_DocType, CDocType)
            CLASS_ENTRY(CLSID_FeatureMatrix, FeatureMatrix)
            CLASS_ENTRY(CLSID_Publisher, CPublisher)
            CLASS_ENTRY(CLSID_ResourcePalette, ResourcePalette)
            CLASS_ENTRY(CLSID_TimelineBuilder, TimelineBuilder)
            CLASS_ENTRY(CLSID_TimelineBuilderFactory, TimelineBuilderFactory)

        END_CLASS_ENTRY

        public:
            void SetResPath(const std::string& resPath) {m_resPath = resPath;}
            const std::string& GetResPath() {return m_resPath;}

        private:
            std::string m_resPath;

    END_MODULE

    
    CreateJSModule g_createJSModule;

    extern "C" FCMPLUGIN_IMP_EXP FCM::Result PluginBoot(FCM::PIFCMCallback pCallback)
    {
        FCM::Result res;
        std::string langCode;
        std::string modulePath;

        res = g_createJSModule.init(pCallback);

        Utils::GetModuleFilePath(modulePath, pCallback);
        Utils::GetLanguageCode(pCallback, langCode);

        g_createJSModule.SetResPath(modulePath + "../res/" + langCode + "/");
        return res;
    }

    extern "C" FCMPLUGIN_IMP_EXP FCM::Result PluginGetClassInfo(
        FCM::PIFCMCalloc pCalloc, 
        FCM::PFCMClassInterfaceInfo* ppClassInfo)
    {
        return g_createJSModule.getClassInfo(pCalloc, ppClassInfo);
    }

    extern "C" FCMPLUGIN_IMP_EXP FCM::Result PluginGetClassObject(
        FCM::PIFCMUnknown pUnkOuter, 
        FCM::ConstRefFCMCLSID clsid, 
        FCM::ConstRefFCMIID iid, 
        FCM::PPVoid pAny)
    {
        return g_createJSModule.getClassObject(pUnkOuter, clsid, iid, pAny);
    }

    // Register the plugin - Register plugin as both DocType and Publisher
    extern "C" FCMPLUGIN_IMP_EXP FCM::Result PluginRegister(FCM::PIFCMPluginDictionary pPluginDict)
    {
        FCM::Result res = FCM_SUCCESS;

        AutoPtr<IFCMDictionary> pDictionary = pPluginDict;

        AutoPtr<IFCMDictionary> pPlugins;
        pDictionary->AddLevel((const FCM::StringRep8)kFCMComponent, pPlugins.m_Ptr);
    
        res = RegisterDocType(pPlugins, g_createJSModule.GetResPath());
        if (FCM_FAILURE_CODE(res))
        {
            return res;
        }
        
        res = RegisterPublisher(pPlugins, CLSID_DocType);

        return res;
    }

    extern "C" FCMPLUGIN_IMP_EXP FCM::U_Int32 PluginCanUnloadNow(void)
    {
        return g_createJSModule.canUnloadNow();
    }

    extern "C" FCMPLUGIN_IMP_EXP FCM::Result PluginShutdown()
    {
        g_createJSModule.finalize();

        return FCM_SUCCESS;
    }

};
