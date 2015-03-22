// This file is part of the "irrRenderer".
// For conditions of distribution and use, see copyright notice in irrRenderer.h

#include "irrRenderer.h"


irr::video::CRenderer* createRenderer(irr::IrrlichtDevice* device, const irr::c8* shaderDir)
{
    return new irr::video::CRenderer(device, shaderDir);
}
