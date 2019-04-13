/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2018 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "FileSystem.hpp"
#include "core/TCoreEnv.hpp"

namespace rz
{

IFile *CFileSystem::OpenFile(const char *asName, const char *asMode) const
{
	//mCoreEnv.pLog->Write("Opening the file %s (Mode: %s)", asName, asMode);
	return nullptr;
};

void CFileSystem::CloseFile(const IFile &apFile)
{
	//mCoreEnv.pLog->Write("Closing the file %s (%p)", apFile->GetName(), apFile);
};

}; // namespace rz