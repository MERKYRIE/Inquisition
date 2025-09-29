#pragma once

struct Inq_File_SInstance
{
    SDL_IOStream * FData;
};

void Inq_File_IConstruct(Inq_File_SInstance *const AInstance , char const*const APath);
bool Inq_File_IRead(Inq_File_SInstance *const AInstance , void *const APointer , Sint64 ASize);
bool Inq_File_IReadCharacter(Inq_File_SInstance *const AInstance , char *const ACharacter);
bool Inq_File_IReadString(Inq_File_SInstance *const AInstance , Inq_String_SInstance *const AString , bool AIsSpaceDelimiting);
bool Inq_File_IReadIntegral(Inq_File_SInstance *const AInstance , Sint64 *const AIntegral);
void Inq_File_IDeconstruct(Inq_File_SInstance *const AInstance);