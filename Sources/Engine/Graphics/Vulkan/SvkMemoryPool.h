/* Copyright (c) 2020 Sultim Tsyrendashiev
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#ifndef SE_INCL_SVKSTATICMEMORYPOOL_H
#define SE_INCL_SVKSTATICMEMORYPOOL_H
#ifdef PRAGMA_ONCE
#pragma once
#endif
#ifdef SE1_VULKAN

#include <Engine/Graphics/Vulkan/VulkanInclude.h>
#include <Engine/Templates/StaticStackArray.cpp>
#include <Engine/VulkanMemoryAllocator/include/vk_mem_alloc.h>

class SvkMemoryPool
{
private:
  VmaAllocator m_allocator;

public:
  SvkMemoryPool(VkInstance instance, VkDevice device, VkPhysicalDevice physicalDevice, uint32_t preferredSize);
  ~SvkMemoryPool();

  // Allocate memory with specified size, out params are memory and offset in it.
  // Returns handle which must be used to free memory.
  // Returns 0 if couldn't allocate
  VmaAllocation Allocate(VkMemoryAllocateInfo allocInfo, VkMemoryRequirements memReqs, VkDeviceMemory &outMemory, uint32_t &outOffset);

  // Free allocated memory. Allocation is a pointer that was returned in Allocate.
  void Free(VmaAllocation allocation);
};

#endif // SE1_VULKAN
#endif