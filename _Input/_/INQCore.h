#pragma once

#include"../SimpleDirectMediaLayer/SDL.h"
#include"../SimpleDirectMediaLayer/TrueTypeFont/SDL_ttf.h"

void Inq_Core_IInitialize(void);
void Inq_Core_IInitiate(void);
void Inq_Core_IDeinitialize(void);

typedef struct Inq_Array_SInstance Inq_Array_SInstance;

typedef struct Inq_Entity_SInstance Inq_Entity_SInstance;

typedef struct Inq_File_SInstance Inq_File_SInstance;

typedef struct Inq_Font_SInstance Inq_Font_SInstance;
typedef struct Inq_Font_SArray Inq_Font_SArray;

typedef struct Inq_Image_SInstance Inq_Image_SInstance;

typedef struct Inq_Inquisitor_SInstance Inq_Inquisitor_SInstance;

typedef struct Inq_Partition_SInstance Inq_Partition_SInstance;

typedef struct Inq_Rectangle_SInstance Inq_Rectangle_SInstance;

typedef struct Inq_Space_SMatrix Inq_Space_SMatrix;

typedef struct Inq_String_SInstance Inq_String_SInstance;
typedef struct Inq_String_SArray Inq_String_SArray;

typedef struct Inq_Surface_SInstance Inq_Surface_SInstance;

typedef struct Inq_Terrain_SInstance Inq_Terrain_SInstance;

typedef struct Inq_Text_SInstance Inq_Text_SInstance;
typedef struct Inq_Text_SArray Inq_Text_SArray;

typedef struct Inq_Tile_SInstance Inq_Tile_SInstance;

/*
struct Inq_Keyboard_SKey;

struct Inq_Mouse_SAbsolute;
struct Inq_Mouse_SButton;
struct Inq_Mouse_SCursor;
struct Inq_Mouse_SPixel;
struct Inq_Mouse_SRectangle;
struct Inq_Mouse_SRelative;
struct Inq_Mouse_SSquare;
struct Inq_Mouse_SWheel;
*/

#include"INQTile.h"
#include"INQRectangle.h"
#include"INQSurface.h"
#include"INQArray.h"
#include"INQDebug.h"
#include"INQEntity.h"
#include"INQFile.h"
#include"INQString.h"
#include"INQImage.h"
#include"INQText.h"
#include"INQFont.h"
#include"INQGlob.h"
#include"INQInquisitor.h"
#include"INQIntegral.h"
#include"INQTerrain.h"
#include"INQPartition.h"
#include"INQReal.h"
#include"INQSpace.h"
#include"INQTypeface.h"
#include"INQVideo.h"

/*
#include"INQInterface.h"
#include"INQKeyboard.h"
#include"INQMouse.h"
#include"INQTime.h"
#include"INQKey.h"
#include"INQAbsolute.h"
#include"INQButton.h"
#include"INQCursor.h"
#include"INQPixel.h"
#include"INQRectangle.h"
#include"INQRelative.h"
#include"INQSquare.h"
#include"INQWheel.h"
*/