/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V2.h"
#include "substrate_types_V2.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V2(parser_context_t* c, pd_AccountId_V2_t* v);
parser_error_t _readAccountIndex_V2(parser_context_t* c, pd_AccountIndex_V2_t* v);
parser_error_t _readAccountVoteSplit_V2(parser_context_t* c, pd_AccountVoteSplit_V2_t* v);
parser_error_t _readAccountVoteStandard_V2(parser_context_t* c, pd_AccountVoteStandard_V2_t* v);
parser_error_t _readAccountVote_V2(parser_context_t* c, pd_AccountVote_V2_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V2(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V2_t* v);
parser_error_t _readBoxCallOrHashOfT_V2(parser_context_t* c, pd_BoxCallOrHashOfT_V2_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V2(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V2_t* v);
parser_error_t _readBoxEquivocationProofHeader_V2(parser_context_t* c, pd_BoxEquivocationProofHeader_V2_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V2(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V2_t* v);
parser_error_t _readBoxMultiLocation_V2(parser_context_t* c, pd_BoxMultiLocation_V2_t* v);
parser_error_t _readBoxPalletsOrigin_V2(parser_context_t* c, pd_BoxPalletsOrigin_V2_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V2(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V2_t* v);
parser_error_t _readBoxVersionedMultiAssets_V2(parser_context_t* c, pd_BoxVersionedMultiAssets_V2_t* v);
parser_error_t _readBoxVersionedMultiLocation_V2(parser_context_t* c, pd_BoxVersionedMultiLocation_V2_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V2(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V2_t* v);
parser_error_t _readBoxVersionedXcmTuple_V2(parser_context_t* c, pd_BoxVersionedXcmTuple_V2_t* v);
parser_error_t _readCallHashOf_V2(parser_context_t* c, pd_CallHashOf_V2_t* v);
parser_error_t _readCodeHash_V2(parser_context_t* c, pd_CodeHash_V2_t* v);
parser_error_t _readCompactAccountIndex_V2(parser_context_t* c, pd_CompactAccountIndex_V2_t* v);
parser_error_t _readCompactGas_V2(parser_context_t* c, pd_CompactGas_V2_t* v);
parser_error_t _readCompactPerBill_V2(parser_context_t* c, pd_CompactPerBill_V2_t* v);
parser_error_t _readConfigOpBalanceOfT_V2(parser_context_t* c, pd_ConfigOpBalanceOfT_V2_t* v);
parser_error_t _readConfigOpPerbill_V2(parser_context_t* c, pd_ConfigOpPerbill_V2_t* v);
parser_error_t _readConfigOpPercent_V2(parser_context_t* c, pd_ConfigOpPercent_V2_t* v);
parser_error_t _readConfigOpu32_V2(parser_context_t* c, pd_ConfigOpu32_V2_t* v);
parser_error_t _readConviction_V2(parser_context_t* c, pd_Conviction_V2_t* v);
parser_error_t _readEcdsaSignature_V2(parser_context_t* c, pd_EcdsaSignature_V2_t* v);
parser_error_t _readElectionScore_V2(parser_context_t* c, pd_ElectionScore_V2_t* v);
parser_error_t _readEraIndex_V2(parser_context_t* c, pd_EraIndex_V2_t* v);
parser_error_t _readEthereumAddress_V2(parser_context_t* c, pd_EthereumAddress_V2_t* v);
parser_error_t _readHeadData_V2(parser_context_t* c, pd_HeadData_V2_t* v);
parser_error_t _readHeartbeatBlockNumber_V2(parser_context_t* c, pd_HeartbeatBlockNumber_V2_t* v);
parser_error_t _readHrmpChannelId_V2(parser_context_t* c, pd_HrmpChannelId_V2_t* v);
parser_error_t _readIdentityFields_V2(parser_context_t* c, pd_IdentityFields_V2_t* v);
parser_error_t _readJudgementBalanceOfT_V2(parser_context_t* c, pd_JudgementBalanceOfT_V2_t* v);
parser_error_t _readKeyOwnerProof_V2(parser_context_t* c, pd_KeyOwnerProof_V2_t* v);
parser_error_t _readKeyValue_V2(parser_context_t* c, pd_KeyValue_V2_t* v);
parser_error_t _readKey_V2(parser_context_t* c, pd_Key_V2_t* v);
parser_error_t _readKeys_V2(parser_context_t* c, pd_Keys_V2_t* v);
parser_error_t _readLeasePeriodOfT_V2(parser_context_t* c, pd_LeasePeriodOfT_V2_t* v);
parser_error_t _readLookupSource_V2(parser_context_t* c, pd_LookupSource_V2_t* v);
parser_error_t _readLookupasStaticLookupSource_V2(parser_context_t* c, pd_LookupasStaticLookupSource_V2_t* v);
parser_error_t _readMemberCount_V2(parser_context_t* c, pd_MemberCount_V2_t* v);
parser_error_t _readMultiSignature_V2(parser_context_t* c, pd_MultiSignature_V2_t* v);
parser_error_t _readMultiSigner_V2(parser_context_t* c, pd_MultiSigner_V2_t* v);
parser_error_t _readNextConfigDescriptor_V2(parser_context_t* c, pd_NextConfigDescriptor_V2_t* v);
parser_error_t _readOpaqueCall_V2(parser_context_t* c, pd_OpaqueCall_V2_t* v);
parser_error_t _readOptionAccountId_V2(parser_context_t* c, pd_OptionAccountId_V2_t* v);
parser_error_t _readOptionElectionScore_V2(parser_context_t* c, pd_OptionElectionScore_V2_t* v);
parser_error_t _readOptionMultiSignature_V2(parser_context_t* c, pd_OptionMultiSignature_V2_t* v);
parser_error_t _readOptionMultiSigner_V2(parser_context_t* c, pd_OptionMultiSigner_V2_t* v);
parser_error_t _readOptionProxyType_V2(parser_context_t* c, pd_OptionProxyType_V2_t* v);
parser_error_t _readOptionReferendumIndex_V2(parser_context_t* c, pd_OptionReferendumIndex_V2_t* v);
parser_error_t _readOptionStatementKind_V2(parser_context_t* c, pd_OptionStatementKind_V2_t* v);
parser_error_t _readOptionTimepoint_V2(parser_context_t* c, pd_OptionTimepoint_V2_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V2(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V2_t* v);
parser_error_t _readOptionXcmVersion_V2(parser_context_t* c, pd_OptionXcmVersion_V2_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V2(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V2_t* v);
parser_error_t _readOverweightIndex_V2(parser_context_t* c, pd_OverweightIndex_V2_t* v);
parser_error_t _readParaId_V2(parser_context_t* c, pd_ParaId_V2_t* v);
parser_error_t _readParachainsInherentDataHeader_V2(parser_context_t* c, pd_ParachainsInherentDataHeader_V2_t* v);
parser_error_t _readPerbill_V2(parser_context_t* c, pd_Perbill_V2_t* v);
parser_error_t _readPercent_V2(parser_context_t* c, pd_Percent_V2_t* v);
parser_error_t _readProxyType_V2(parser_context_t* c, pd_ProxyType_V2_t* v);
parser_error_t _readPvfCheckStatement_V2(parser_context_t* c, pd_PvfCheckStatement_V2_t* v);
parser_error_t _readReferendumIndex_V2(parser_context_t* c, pd_ReferendumIndex_V2_t* v);
parser_error_t _readRegistrarIndex_V2(parser_context_t* c, pd_RegistrarIndex_V2_t* v);
parser_error_t _readRenouncing_V2(parser_context_t* c, pd_Renouncing_V2_t* v);
parser_error_t _readRewardDestination_V2(parser_context_t* c, pd_RewardDestination_V2_t* v);
parser_error_t _readSessionIndex_V2(parser_context_t* c, pd_SessionIndex_V2_t* v);
parser_error_t _readSolutionOrSnapshotSize_V2(parser_context_t* c, pd_SolutionOrSnapshotSize_V2_t* v);
parser_error_t _readStatementKind_V2(parser_context_t* c, pd_StatementKind_V2_t* v);
parser_error_t _readSupportsAccountId_V2(parser_context_t* c, pd_SupportsAccountId_V2_t* v);
parser_error_t _readTimepoint_V2(parser_context_t* c, pd_Timepoint_V2_t* v);
parser_error_t _readTupleAccountIdData_V2(parser_context_t* c, pd_TupleAccountIdData_V2_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V2(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V2_t* v);
parser_error_t _readValidationCodeHash_V2(parser_context_t* c, pd_ValidationCodeHash_V2_t* v);
parser_error_t _readValidationCode_V2(parser_context_t* c, pd_ValidationCode_V2_t* v);
parser_error_t _readValidatorPrefs_V2(parser_context_t* c, pd_ValidatorPrefs_V2_t* v);
parser_error_t _readValidatorSignature_V2(parser_context_t* c, pd_ValidatorSignature_V2_t* v);
parser_error_t _readVecAccountId_V2(parser_context_t* c, pd_VecAccountId_V2_t* v);
parser_error_t _readVecKeyValue_V2(parser_context_t* c, pd_VecKeyValue_V2_t* v);
parser_error_t _readVecKey_V2(parser_context_t* c, pd_VecKey_V2_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V2(parser_context_t* c, pd_VecLookupasStaticLookupSource_V2_t* v);
parser_error_t _readVecTupleAccountIdData_V2(parser_context_t* c, pd_VecTupleAccountIdData_V2_t* v);
parser_error_t _readVestingInfoBalanceOfTBlockNumber_V2(parser_context_t* c, pd_VestingInfoBalanceOfTBlockNumber_V2_t* v);
parser_error_t _readVote_V2(parser_context_t* c, pd_Vote_V2_t* v);
parser_error_t _readWeightLimit_V2(parser_context_t* c, pd_WeightLimit_V2_t* v);
parser_error_t _readWeight_V2(parser_context_t* c, pd_Weight_V2_t* v);
parser_error_t _readXcmVersion_V2(parser_context_t* c, pd_XcmVersion_V2_t* v);
parser_error_t _readschedulePeriodBlockNumber_V2(parser_context_t* c, pd_schedulePeriodBlockNumber_V2_t* v);
parser_error_t _readschedulePriority_V2(parser_context_t* c, pd_schedulePriority_V2_t* v);
parser_error_t _readAccountIdLookupOfT_V2(parser_context_t* c, pd_AccountIdLookupOfT_V2_t* v);
parser_error_t _readOptionCompactu128_V2(parser_context_t* c, pd_OptionCompactu128_V2_t* v);

// toString functions
parser_error_t _toStringAccountId_V2(
    const pd_AccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V2(
    const pd_AccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V2(
    const pd_AccountVoteSplit_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V2(
    const pd_AccountVoteStandard_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V2(
    const pd_AccountVote_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V2(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V2(
    const pd_BoxCallOrHashOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V2(
    const pd_BoxEquivocationProofHashBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V2(
    const pd_BoxEquivocationProofHeader_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V2(
    const pd_BoxIdentityInfoMaxAdditionalFields_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V2(
    const pd_BoxMultiLocation_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V2(
    const pd_BoxPalletsOrigin_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V2(
    const pd_BoxRawSolutionSolutionOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V2(
    const pd_BoxVersionedMultiAssets_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V2(
    const pd_BoxVersionedMultiLocation_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V2(
    const pd_BoxVersionedXcmTasSysConfigCall_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V2(
    const pd_BoxVersionedXcmTuple_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V2(
    const pd_CallHashOf_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V2(
    const pd_CodeHash_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V2(
    const pd_CompactAccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactGas_V2(
    const pd_CompactGas_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V2(
    const pd_CompactPerBill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V2(
    const pd_ConfigOpBalanceOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V2(
    const pd_ConfigOpPerbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V2(
    const pd_ConfigOpPercent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V2(
    const pd_ConfigOpu32_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V2(
    const pd_Conviction_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V2(
    const pd_EcdsaSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V2(
    const pd_ElectionScore_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V2(
    const pd_EraIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V2(
    const pd_EthereumAddress_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V2(
    const pd_HeadData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V2(
    const pd_HeartbeatBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V2(
    const pd_HrmpChannelId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V2(
    const pd_IdentityFields_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V2(
    const pd_JudgementBalanceOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V2(
    const pd_KeyOwnerProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V2(
    const pd_KeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V2(
    const pd_Key_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V2(
    const pd_Keys_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V2(
    const pd_LookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V2(
    const pd_LeasePeriodOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V2(
    const pd_LookupasStaticLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V2(
    const pd_MemberCount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V2(
    const pd_MultiSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V2(
    const pd_MultiSigner_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V2(
    const pd_NextConfigDescriptor_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V2(
    const pd_OpaqueCall_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V2(
    const pd_OptionAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V2(
    const pd_OptionElectionScore_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V2(
    const pd_OptionMultiSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V2(
    const pd_OptionMultiSigner_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V2(
    const pd_OptionProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V2(
    const pd_OptionReferendumIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V2(
    const pd_OptionStatementKind_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V2(
    const pd_OptionTimepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V2(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V2(
    const pd_OptionXcmVersion_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V2(
    const pd_OptionschedulePeriodBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V2(
    const pd_OverweightIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V2(
    const pd_ParaId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V2(
    const pd_ParachainsInherentDataHeader_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V2(
    const pd_Perbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V2(
    const pd_Percent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V2(
    const pd_ProxyType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPvfCheckStatement_V2(
    const pd_PvfCheckStatement_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V2(
    const pd_ReferendumIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V2(
    const pd_RegistrarIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V2(
    const pd_Renouncing_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V2(
    const pd_RewardDestination_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V2(
    const pd_SessionIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V2(
    const pd_SolutionOrSnapshotSize_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V2(
    const pd_StatementKind_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V2(
    const pd_SupportsAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V2(
    const pd_Timepoint_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V2(
    const pd_TupleAccountIdData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V2(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCodeHash_V2(
    const pd_ValidationCodeHash_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V2(
    const pd_ValidationCode_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V2(
    const pd_ValidatorPrefs_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorSignature_V2(
    const pd_ValidatorSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V2(
    const pd_VecAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V2(
    const pd_VecKeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V2(
    const pd_VecKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V2(
    const pd_VecLookupasStaticLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V2(
    const pd_VecTupleAccountIdData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfoBalanceOfTBlockNumber_V2(
    const pd_VestingInfoBalanceOfTBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V2(
    const pd_Vote_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V2(
    const pd_WeightLimit_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V2(
    const pd_Weight_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V2(
    const pd_XcmVersion_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V2(
    const pd_schedulePeriodBlockNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V2(
    const pd_schedulePriority_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT_V2(
    const pd_AccountIdLookupOfT_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCompactu128_V2(
    const pd_OptionCompactu128_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
