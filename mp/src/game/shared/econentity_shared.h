#pragma once

#include "baseviewmodel_shared.h"

#ifdef CLIENT_DLL
#include <client/c_baseanimating.h>
#else
static_assert(false, "FIXME: server econ entities");
#endif

#ifdef CLIENT_DLL
#define CEconEntity C_EconEntity
#endif

class CEconEntity : public CBaseAnimating
{
public:
	DECLARE_CLASS(CEconEntity, CBaseAnimating);
	DECLARE_NETWORKCLASS();
	DECLARE_PREDICTABLE();

	virtual bool ShouldShowToolTip() const;
	virtual bool OnFireEvent(C_BaseViewModel *pViewModel, const Vector& origin, const QAngle& angles, int event, const char *options);
	virtual bool ShouldDrawParticleSystems();
	virtual void UpdateAttachmentModels();
	virtual bool ViewModel_IsTransparent();
	virtual bool ViewModel_IsUsingFBTexture();
	virtual bool IsOverridingViewmodel();
	virtual int DrawOverriddenViewmodel(CBaseViewModel* viewmodel, int flags);
	virtual void GetAttachment(const char*, Vector&);
	virtual void GetAttachment(const char*, Vector&, QAngle&);
	virtual void ViewModelAttachmentBlending(CStudioHdr*, Vector*, Quaternion*, float, int);
	virtual void SetMaterialOverride(int, const char*);
	virtual void SetMaterialOverride(int, CMaterialReference&);
	virtual void* GetAttributeManager();
	virtual void* GetAttributeContainer();
	virtual void* GetAttributeOwner();
	virtual void* GetAttributeList();
	virtual void ReapplyProvision();
	virtual void UpdateBodygroups(C_BaseCombatCharacter*, int);
	virtual void TranslateViewmodelHandActivityInternal(Activity);

	PADDING(24);

	struct AttributeManager
	{
		PADDING(52);
		int m_iReapplyProvisionParity;
		EHANDLE m_hOuter;
		PADDING(4);
		int m_ProviderType;

		struct ScriptCreatedAttribute
		{
			PADDING(4);
			int m_iAttributeDefinitionIndex;

			union
			{
				int m_iRawValue32;
				float m_flValue;
			};

			int m_nRefundableCurrency;
		};

		struct ScriptCreatedItem
		{
			PADDING(36);
			int m_iItemDefinitionIndex;
			int m_iEntityQuality;
			int m_iEntityLevel;
			PADDING(8);
			int m_iItemIDHigh;
			int m_iItemIDLow;
			int m_iAccountID;
			PADDING(84);
			int m_iTeamNumber;
			bool m_bInitialized;
			PADDING(8);
			CUtlVector<ScriptCreatedAttribute> m_Attributes;
			PADDING(8);
			CUtlVector<ScriptCreatedAttribute> m_NetworkedDynamicAttributesForDemos;
			PADDING(8);

			bool m_bOnlyIterateItemViewAttributes;
		};

		PADDING(28);
		ScriptCreatedItem m_Item;
	};
	AttributeManager m_AttributeManager;

	PADDING(4);
	bool m_bValidatedAttachedEntity;
	PADDING(24);
	EHANDLE m_Something;
};