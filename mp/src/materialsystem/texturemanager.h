#pragma once

enum ImageFormat;
class ITexture;
class ITextureInternal;
class ITextureRegenerator;
class IVTFTexture;
enum RenderTargetSizeMode_t;
enum RenderTargetType_t;

class ITextureManager
{
public:
	virtual void Init(int) = 0;
	virtual void Shutdown() = 0;

	virtual void AllocateStandardRenderTargets() = 0;
	virtual void FreeStandardRenderTargets() = 0;
	virtual void CacheExternalStandardRenderTargets() = 0;

	virtual void CreateProceduralTexture(const char*, const char*, int, int, int, ImageFormat, int, ITextureRegenerator*) = 0;
	virtual void CreateRenderTargetTexture(const char*, int, int, RenderTargetSizeMode_t, ImageFormat, RenderTargetType_t, uint32_t, uint32_t) = 0;

	virtual void FindOrLoadTexture(const char*, const char*, int) = 0;

	virtual void ResetTextureFilteringState() = 0;

	virtual void ReloadTextures() = 0;
	virtual void ReleaseTextures() = 0;
	virtual void RestoreRenderTargets() = 0;
	virtual void RestoreNonRenderTargetTextures() = 0;

	virtual void SuspendTextureStreaming() = 0;
	virtual void ResumeTextureStreaming() = 0;

	virtual void RemoveUnusedTextures() = 0;
	virtual void DebugPrintUsedTextures() = 0;

	virtual void RequestNextTextureID() = 0;

	virtual void ErrorTexture() = 0;
	virtual void NormalizationCubemap() = 0;
	virtual void SignedNormalizationCubemap() = 0;
	virtual void ColorCorrectionTexture() = 0;
	virtual void ShadowNoise2D() = 0;
	virtual void IdentityLightwarp() = 0;
	virtual void FullFrameDepthTexture() = 0;
	virtual void DebugLuxels2D() = 0;

	virtual void GenerateErrorTexture(ITexture*, IVTFTexture*) = 0;
	virtual void SetColorCorrectionTexture(int, ITextureInternal*) = 0;

	virtual void ForceAllTexturesIntoHardware() = 0;
	virtual bool IsTextureLoaded(const char* texName) = 0;

	virtual void MarkUnreferencedTextureForCleanup(ITextureInternal*) = 0;

	virtual void RemoveTexture(ITextureInternal*) = 0;

	virtual int FindNext(int index, ITextureInternal** pOut) = 0;

	////////////////////////
	// ... incomplete ... //
	////////////////////////
};