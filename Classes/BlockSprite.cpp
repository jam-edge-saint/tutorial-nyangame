#include "BlockSprite.h"

BlockSprite::BlockSprite()
{
}

BlockSprite::~BlockSprite()
{
}

BlockSprite* BlockSprite::createWithBlockType(kBlock blockType)
{
    BlockSprite* pRet = new BlockSprite();
    if(pRet && pRet->initWithBlockType(blockType))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool BlockSprite::initWithBlockType(kBlock blockType)
{
    if(false == CCSprite::initWithFile(getBlockImageFimeName(blockType)))
    {
        return false;
    }
    
    m_blockType = blockType;
    
    return true;
}

const char* BlockSprite::getBlockImageFimeName(kBlock blockType)
{
    switch(blockType)
    {
        case kBlockRed:
            return "red.png";
        
        case kBlockBlue:
            return "blue.png";
            
        case kBlockYellow:
            return "yellow.png";
            
        case kBlockGreen:
            return "green.png";
            
        case kBlockGray:
            return "gray.png";
            
        default:
            CCAssert(false, "invalid blocktype");
            return "";
    }
}