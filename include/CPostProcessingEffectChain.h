// This file is part of the "irrRenderer".
// For conditions of distribution and use, see copyright notice in irrRenderer.h

#ifndef CPOSTPROCESSINGEFFECTCHAIN_H
#define CPOSTPROCESSINGEFFECTCHAIN_H

#include <irrlicht.h>
#include "CPostProcessingEffect.h"
#include "E_POST_PROCESSING_EFFECT.h"
#include "IShaderDefaultPostProcessCallback.h"

namespace irr
{
namespace video
{

class CRenderer;
class SShaderSource;

class CPostProcessingEffectChain
{
    public:
        CPostProcessingEffectChain(irr::video::CRenderer* renderer);
        ~CPostProcessingEffectChain();

        irr::u32 attachEffect(irr::video::CPostProcessingEffect* effect);
        irr::video::CPostProcessingEffect* createEffect(irr::video::SShaderSource &effectShader, irr::video::IShaderConstantSetCallBack* callback= new irr::video::IShaderDefaultPostProcessCallback);
        irr::video::CPostProcessingEffect* createEffect(irr::video::E_POSTPROCESSING_EFFECT type);

        void detachEffect(irr::u32 index);
        void detachEffect(irr::video::CPostProcessingEffect* effect);

        void removeEffect(irr::u32 index);

        irr::u32 getEffectCount() const;
        irr::u32 getActiveEffectCount() const;
        irr::video::CPostProcessingEffect* getEffectFromIndex(irr::u32 index);
        irr::u32 getEffectIndex(irr::video::CPostProcessingEffect* effect) const;

        void setActive(bool active);
        bool isActive();

    private:
        irr::video::CRenderer* Renderer;
        bool Active;
        irr::core::array<irr::video::CPostProcessingEffect*> Effects;
};

}
}

#endif // CPOSTPROCESSINGEFFECTCHAIN_H
