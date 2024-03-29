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

#pragma once
#include <Arduino.h>
#include <LittleFS.h>


class FileSystem

{
private:
    size_t maxFileSpace = 0;
    size_t usedFileSpace = 0;
    
  File openFile(char *fileName,char * mode);

public:
    FileSystem(void);
   
    boolean mount();
    boolean WriteNewFile (char* fileName, char* txt);
    String ReadFile (char* fileName);
    boolean AppendTextToFile (char* fileName, char* txt);

  
};
