#pragma once

#include"../SimpleDirectMediaLayer/SDL.h"
#include"../SimpleDirectMediaLayer/Image/SDL_image.h"
#include"../SimpleDirectMediaLayer/TrueTypeFont/SDL_ttf.h"

void Inq_Core_IInitialize(void);
void Inq_Core_IInitiate(void);
void Inq_Core_IDeinitialize(void);

typedef struct Inq_Animation_SInstance Inq_Animation_SInstance;
typedef struct Inq_Animation_SArray Inq_Animation_SArray;

typedef struct Inq_Animator_SInstance Inq_Animator_SInstance;

typedef struct Inq_Array_SInstance Inq_Array_SInstance;

typedef struct Inq_Entity_SInstance Inq_Entity_SInstance;
typedef struct Inq_Entity_SList Inq_Entity_SList;
typedef struct Inq_Entity_SNode Inq_Entity_SNode;

typedef union Inq_EntityData_UInstance Inq_EntityData_UInstance;

typedef struct Inq_EntityStorage_SInstance Inq_EntityStorage_SInstance;
typedef struct Inq_EntityStorage_SArray Inq_EntityStorage_SArray;

typedef struct Inq_File_SInstance Inq_File_SInstance;

typedef struct Inq_Font_SInstance Inq_Font_SInstance;
typedef struct Inq_Font_SArray Inq_Font_SArray;

typedef struct Inq_Frame_SInstance Inq_Frame_SInstance;
typedef struct Inq_Frame_SArray Inq_Frame_SArray;

typedef struct Inq_Husk_SInstance Inq_Husk_SInstance;

typedef struct Inq_Image_SInstance Inq_Image_SInstance;
typedef struct Inq_Image_SArray Inq_Image_SArray;

typedef struct Inq_Key_SInstance Inq_Key_SInstance;
typedef struct Inq_Key_SArray Inq_Key_SArray;

typedef struct Inq_List_SInstance Inq_List_SInstance;

typedef struct Inq_Name_SInstance Inq_Name_SInstance;

typedef struct Inq_Node_SInstance Inq_Node_SInstance;

typedef struct Inq_Partition_SInstance Inq_Partition_SInstance;
typedef struct Inq_Partition_Array Inq_Partition_Array;

typedef struct Inq_Player_SInstance Inq_Player_SInstance;

typedef struct Inq_Pointer_SInstance Inq_Pointer_SInstance;

typedef struct Inq_Rectangle_SInstance Inq_Rectangle_SInstance;

typedef struct Inq_Sprite_SInstance Inq_Sprite_SInstance;

typedef struct Inq_SubHusk_SInstance Inq_SubHusk_SInstance;

typedef struct Inq_String_SInstance Inq_String_SInstance;
typedef struct Inq_String_SArray Inq_String_SArray;

typedef struct Inq_Terrain_SInstance Inq_Terrain_SInstance;

typedef struct Inq_Text_SInstance Inq_Text_SInstance;
typedef struct Inq_Text_SArray Inq_Text_SArray;

typedef struct Inq_Wall_SInstance Inq_Wall_SInstance;

/*
struct Inq_Mouse_SAbsolute;
struct Inq_Mouse_SButton;
struct Inq_Mouse_SCursor;
struct Inq_Mouse_SPixel;
struct Inq_Mouse_SRectangle;
struct Inq_Mouse_SRelative;
struct Inq_Mouse_SSquare;
struct Inq_Mouse_SWheel;
*/

#include"INQTime.h"
#include"INQKeyboard.h"
#include"INQEntityStorage.h"
#include"INQNode.h"
#include"INQPointer.h"
#include"INQList.h"
#include"INQSprite.h"
#include"INQFrame.h"
#include"INQHusk.h"
#include"INQRectangle.h"
#include"INQName.h"
#include"INQWall.h"
#include"INQAtlas.h"
#include"INQArray.h"
#include"INQDebug.h"
#include"INQSubHusk.h"
#include"INQFile.h"
#include"INQString.h"
#include"INQAnimation.h"
#include"INQAnimator.h"
#include"INQPlayer.h"
#include"INQEntityData.h"
#include"INQEntity.h"
#include"INQKey.h"
#include"INQImage.h"
#include"INQText.h"
#include"INQFont.h"
#include"INQGlob.h"
#include"INQIntegral.h"
#include"INQTerrain.h"
#include"INQPartition.h"
#include"INQReal.h"
#include"INQTypeface.h"
#include"INQVideo.h"

/*
#include"INQInterface.h"
#include"INQMouse.h"
#include"INQAbsolute.h"
#include"INQButton.h"
#include"INQCursor.h"
#include"INQPixel.h"
#include"INQRectangle.h"
#include"INQRelative.h"
#include"INQSquare.h"
#include"INQWheel.h"
*/