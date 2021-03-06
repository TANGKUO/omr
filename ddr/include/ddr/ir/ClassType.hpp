/*******************************************************************************
 * Copyright (c) 2016, 2017 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0
 *******************************************************************************/

#ifndef CLASSTYPE_HPP
#define CLASSTYPE_HPP

#include "ddr/config.hpp"

#include "ddr/ir/EnumMember.hpp"
#include "ddr/ir/Field.hpp"
#include "ddr/ir/NamespaceUDT.hpp"
#include "ddr/ir/UDT.hpp"

using std::vector;

class ClassType : public NamespaceUDT
{
public:
	vector<Field *> _fieldMembers;
	vector<EnumMember *> _enumMembers; /* used for anonymous enums*/

	ClassType(size_t size, unsigned int lineNumber = 0);
	virtual ~ClassType();

	virtual bool isAnonymousType();
	virtual void computeFieldOffsets();
	virtual void renameFieldsAndMacros(FieldOverride fieldOverride, Type *replacementType);

	bool operator==(Type const & rhs) const;
	virtual bool compareToClasstype(ClassType const &) const;
};

#endif /* CLASSTYPE_HPP */
