 /*
    This file is part of FileSystem Libary  
    FileSystem Libary is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FileSystem Libary is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FileSystem Libary.  If not, see <http://www.gnu.org/licenses/>.

    Diese Datei ist Teil von Fubar.

    Fubar ist Freie Software: Sie können es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veröffentlichten Version, weiter verteilen und/oder modifizieren.

    Fubar wird in der Hoffnung, dass es nützlich sein wird, aber
    OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
    Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License für weitere Details.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <https://www.gnu.org/licenses/>.*/

#include <FileSystem.h>
FSInfo fs_info;
SerialDebug Debug(ALL);

FileSystem::FileSystem(LEVEL DebLvl)
{
    Debug.setDebugLevel(DebLvl);
}

boolean FileSystem::mount()
{
    if (LittleFS.begin())
    {
        Debug.print("Mount SPIFFS", "true", DEBUG);
        if (LittleFS.info(fs_info))
        {
            Debug.print("used Bytes", String(fs_info.usedBytes), DEBUG);
            Debug.print("max Size Bytes", String(fs_info.totalBytes), DEBUG);
            return true;
        }
    }
    else
    {
        Debug.print("Mount SPIFFS", "true", ERROR);
    }
    return false;
}

boolean FileSystem::WriteNewFile(char *fileName, char *txt)
{
    
    File file = openFile(fileName, (char *)"w");
    int bytesWritten = file.print(txt);
    file.close();
    if (bytesWritten > 0)
    {
        Debug.print("File write", "success", DEBUG);
        Debug.print("Bytes written", String(bytesWritten), DEBUG);
        return true;
    }
    else
    {
        Debug.print("File write", "failed", ERROR);
        return false;
    }
}


String FileSystem::ReadFile(char *fileName)
{
    String txt = "";
    if (!LittleFS.exists(fileName)){
        Debug.print("File not exists", String(fileName), WARN);
        return "notExists";
    }
    File file = openFile(fileName, (char *)"r");
    
    while(file.available()){
 
        txt+=char(file.read());
    }
    file.close();
    return txt;
}


boolean FileSystem::AppendTextToFile(char *fileName, char *txt)
{
 File file = openFile(fileName, (char *)"a");
    int bytesWritten = file.print(txt);
    file.close();
    if (bytesWritten > 0)
    {
        Debug.print("Data append to file", "success", DEBUG);
        Debug.print("Bytes written", String(bytesWritten), DEBUG);
        return true;
    }
    else
    {
        Debug.print("Data append to file", "failed", ERROR);
        return false;
    }
}

//Private

File FileSystem::openFile(char *fileName, char *mode)
{
    File file = LittleFS.open(fileName, mode);
    if (file)
    {
       Debug.print("File OPEN" , String(fileName) , ERROR);
    }else
    
    {
        Debug.print("Can not open", String(fileName), ERROR);

    }
    
    return file;
}