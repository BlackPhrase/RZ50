/* 
 * This file is part of RZ Engine
 * Copyright (c) 2017-2019 BlackPhrase
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU Lesser General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <memory>
#include "core/CoreTypes.hpp"
#include "core/ICmdProcessor.hpp"
#include "core/IServiceLocator.hpp"

namespace rz
{

struct IServiceLocator;
class CCore;

class CCmdBuffer;
class CCmdExecutor;
class CCmdContainer;

class CCmdProcessor final : public ICmdProcessor
{
public:
	CCmdProcessor(const IServiceLocator &aCoreEnv);
	~CCmdProcessor();
	
	void Init(IServiceLocator &aCoreEnv, CCore *apCore);
	
	void AddCommand(const char *asName, pfnCmdCallback afnCallback, const char *asDesc) override;
	
	void BufferText(const char *asText, InsertMode aeMode) override;
	void ExecText(const char *asText) override;
	
	void ExecBuffer() override;
private:
	std::unique_ptr<CCmdBuffer> mpBuffer;
	std::unique_ptr<CCmdExecutor> mpExecutor;
	std::unique_ptr<CCmdContainer> mpContainer;
	
	const IServiceLocator &mCoreEnv;
};

}; // namespace rz