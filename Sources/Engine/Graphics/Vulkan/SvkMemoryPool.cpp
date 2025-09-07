#include "StdH.h"

#include <stdexcept>

#define VMA_IMPLEMENTATION

#include "SvkMemoryPool.h"

#include <Engine/Base/Console.h>

SvkMemoryPool::SvkMemoryPool(VkInstance instance, VkDevice device, VkPhysicalDevice physicalDevice, uint32_t preferredSize)
{
  VmaAllocatorCreateInfo allocatorCreateInfo = {};

  allocatorCreateInfo.physicalDevice = physicalDevice;
  allocatorCreateInfo.device = device;
  allocatorCreateInfo.instance = instance;
  allocatorCreateInfo.preferredLargeHeapBlockSize = preferredSize;

  if(vmaCreateAllocator(&allocatorCreateInfo, &m_allocator) != VK_SUCCESS) throw std::runtime_error("Can't create Vulkan memory allocator");
}

SvkMemoryPool::~SvkMemoryPool()
{
  vmaDestroyAllocator(m_allocator);
}

VmaAllocation SvkMemoryPool::Allocate(VkMemoryAllocateInfo allocInfo, VkMemoryRequirements memReqs, VkDeviceMemory &outMemory, uint32_t &outOffset)
{
  VmaAllocation allocation = nullptr;
  VmaAllocationInfo allocationInfo = {};
  VmaAllocationCreateInfo allocationCreateInfo = {};

  allocationCreateInfo.usage = VMA_MEMORY_USAGE_GPU_ONLY;

  if(vmaAllocateMemory(m_allocator, &memReqs, &allocationCreateInfo, &allocation, &allocationInfo) != VK_SUCCESS) return nullptr;

  outMemory = allocationInfo.deviceMemory;
  outOffset = allocationInfo.offset;

  return allocation;
}

void SvkMemoryPool::Free(VmaAllocation allocation)
{
  vmaFreeMemory(m_allocator, allocation);
}
