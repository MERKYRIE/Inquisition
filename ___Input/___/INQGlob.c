#include"INQCore.h"

void Inq_Glob_IConstruct(Inq_String_SArray *const AInstance , char const*const APath , char const*const AExtension)
{
    Inq_Array_IConstructVoid(AInstance , sizeof(Inq_String_SInstance));
    char ** LArray;
    Sint32 LCount;
    Inq_Debug_IAssertHandle(LArray = SDL_GlobDirectory(APath , NULL , 0 , &LCount));
    for(Sint64 LIndex = 0 ; LIndex < LCount ; LIndex++)
    {
        SDL_PathInfo LInformation;
        Inq_String_SInstance LFile;
        Inq_String_IConstruct(&LFile , APath);
        Inq_String_SInstance LBuffer;
        Inq_String_IConstruct(&LBuffer , "/");
        Inq_String_IAppend(&LFile , &LBuffer);
        Inq_String_IDeconstruct(&LBuffer);
        Inq_String_IConstruct(&LBuffer , LArray[LIndex]);
        Inq_String_IAppend(&LFile , &LBuffer);
        Inq_String_IDeconstruct(&LBuffer);
        Inq_Debug_IAssertCondition(SDL_GetPathInfo(LFile.FData , &LInformation));
        if(AExtension == NULL)
        {
            if(LInformation.type == SDL_PATHTYPE_DIRECTORY)
            {
                Inq_Array_IPush(AInstance);
                Inq_String_IConstruct(Inq_Array_IGetLast(AInstance) , LFile.FData);
                Inq_String_IGeneralize(Inq_Array_IGetLast(AInstance));
            }
        }
        else
        {
            if(LInformation.type == SDL_PATHTYPE_FILE)
            {
                Inq_String_SInstance LRequestedExtension;
                Inq_String_IConstruct(&LRequestedExtension , AExtension);
                Inq_String_SInstance LFoundExtension;
                Inq_String_IConstruct(&LFoundExtension , Inq_String_IFindLast(&LFile , '.' , 1));
                if(!Inq_String_ICompare(&LFoundExtension , &LRequestedExtension))
                {
                    Inq_Array_IPush(AInstance);
                    Inq_String_IConstruct(Inq_Array_IGetLast(AInstance) , LFile.FData);
                    Inq_String_IGeneralize(Inq_Array_IGetLast(AInstance));
                }
                Inq_String_IDeconstruct(&LRequestedExtension);
                Inq_String_IDeconstruct(&LFoundExtension);
                Inq_String_IDeconstruct(&LFile);
            }
        }
    }
    SDL_free(LArray);
}

void Inq_Glob_IDeconstruct(Inq_String_SArray *const AInstance)
{
    for(Sint64 LIndex = 0 ; LIndex < AInstance->FCount ; LIndex++)
    {
        Inq_String_IDeconstruct(&AInstance->FData[LIndex]);
    }
    Inq_Array_IDeconstruct(AInstance);
}