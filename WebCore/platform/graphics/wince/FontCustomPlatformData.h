/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef FontCustomPlatformData_h
#define FontCustomPlatformData_h

#include "FontRenderingMode.h"
#include "PlatformString.h"
#include <wtf/Noncopyable.h>

namespace WebCore {

    class FontPlatformData;
    class CachedFont;

    class CustomFontCache {
    public:
        virtual bool registerFont(const String& fontName, CachedFont*) = 0;
        virtual void unregisterFont(const String& fontName) = 0;
    };

    struct FontCustomPlatformData : Noncopyable {
        FontCustomPlatformData(const String& name)
            : m_name(name)
        {
        }

        ~FontCustomPlatformData();

        FontPlatformData fontPlatformData(int size, bool bold, bool italic, FontRenderingMode = NormalRenderingMode);
        String m_name;
    };

    FontCustomPlatformData* createFontCustomPlatformData(CachedFont*);

}

#endif