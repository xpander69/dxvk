#include "dxbc_typeinfo.h"

namespace dxvk {
  
  DxbcTypeInfo:: DxbcTypeInfo() { }
  DxbcTypeInfo::~DxbcTypeInfo() { }
  
  
  DxvkSpirvCodeBuffer DxbcTypeInfo::code() const {
    return m_code;
  }
  
  
  uint32_t DxbcTypeInfo::typeVoid(
          DxvkSpirvIdCounter& ids) {
    return this->getTypeId(ids,
      spv::OpTypeVoid, 0, nullptr);
  }
  
  
  uint32_t DxbcTypeInfo::typeBool(
          DxvkSpirvIdCounter& ids) {
    return this->getTypeId(ids,
      spv::OpTypeBool, 0, nullptr);
  }
  
  
  uint32_t DxbcTypeInfo::typeInt(
          DxvkSpirvIdCounter& ids,
          uint32_t            width,
          uint32_t            isSigned) {
    std::array<uint32_t, 2> args = {{ width, isSigned }};
    return this->getTypeId(ids,
      spv::OpTypeInt, args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeFloat(
          DxvkSpirvIdCounter& ids,
          uint32_t            width) {
    return this->getTypeId(ids,
      spv::OpTypeFloat, 1, &width);
  }
  
  
  uint32_t DxbcTypeInfo::typeVector(
          DxvkSpirvIdCounter& ids,
          uint32_t            componentType,
          uint32_t            componentCount) {
    std::array<uint32_t, 2> args = {{ componentType, componentCount }};
    return this->getTypeId(ids,
      spv::OpTypeVector, args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeMatrix(
          DxvkSpirvIdCounter& ids,
          uint32_t            colType,
          uint32_t            colCount) {
    std::array<uint32_t, 2> args = {{ colType, colCount }};
    return this->getTypeId(ids,
      spv::OpTypeMatrix, args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeArray(
          DxvkSpirvIdCounter& ids,
          uint32_t            elementType,
          uint32_t            elementCount) {
    std::array<uint32_t, 2> args = {{ elementType, elementCount }};
    return this->getTypeId(ids,
      spv::OpTypeArray, args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeRuntimeArray(
          DxvkSpirvIdCounter& ids,
          uint32_t            elementType) {
    return this->getTypeId(ids,
      spv::OpTypeRuntimeArray, 1, &elementType);
  }
  
  
  uint32_t DxbcTypeInfo::typePointer(
          DxvkSpirvIdCounter& ids,
          spv::StorageClass   storageClass,
          uint32_t            type) {
    std::array<uint32_t, 2> args = {{ storageClass, type }};
    return this->getTypeId(ids,
      spv::OpTypePointer, args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeFunction(
          DxvkSpirvIdCounter& ids,
          uint32_t            returnType,
          uint32_t            argCount,
    const uint32_t*           argTypes) {
    std::vector<uint32_t> args(argCount + 1);
    args.at(0) = returnType;
    
    for (uint32_t i = 0; i < argCount; i++)
      args.at(i + 1) = argTypes[i];
    
    return this->getTypeId(ids,
      spv::OpTypeFunction,
      args.size(), args.data());
  }
  
  
  uint32_t DxbcTypeInfo::typeStruct(
          DxvkSpirvIdCounter& ids,
          uint32_t            memberCount,
    const uint32_t*           memberTypes) {
    return this->getTypeId(ids,
      spv::OpTypeStruct,
      memberCount,
      memberTypes);
  }
  
  
  uint32_t DxbcTypeInfo::getTypeId(
          DxvkSpirvIdCounter&               ids,
          spv::Op                           op,
          uint32_t                          argCount,
    const uint32_t*                         args) {
    // Since the type info is stored in the code buffer,
    // we can use the code buffer to look up type IDs as
    // well. Result IDs are always stored as argument 1.
    for (auto ins : m_code) {
      bool match = ins.opCode() == op;
      
      for (uint32_t i = 0; i < argCount && match; i++)
        match &= ins.arg(2 + i) == args[i];
      
      if (match)
        return ins.arg(1);
    }
    
    // Type not yet declared, create a new one.
    uint32_t result = ids.nextId();
    m_code.putIns (op, 2 + argCount);
    m_code.putWord(result);
    
    for (uint32_t i = 0; i < argCount; i++)
      m_code.putWord(args[i]);
    return result;
  }
  
  
}