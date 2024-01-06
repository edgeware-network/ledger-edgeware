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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(
    parser_context_t* c, pd_balances_transfer_keep_alive_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(
    parser_context_t* c, pd_balances_transfer_all_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
    parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
    parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
    parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(
    parser_context_t* c, pd_staking_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(
    parser_context_t* c, pd_staking_validate_V2_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V2(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(
    parser_context_t* c, pd_staking_nominate_V2_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(
    parser_context_t* c, pd_staking_chill_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(
    parser_context_t* c, pd_staking_set_payee_V2_t* m)
{
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(
    parser_context_t* c, pd_staking_set_controller_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(
    parser_context_t* c, pd_staking_payout_stakers_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(
    parser_context_t* c, pd_staking_rebond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(
    parser_context_t* c, pd_session_set_keys_V2_t* m)
{
    CHECK_ERROR(_readKeys_V2(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(
    parser_context_t* c, pd_session_purge_keys_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(
    parser_context_t* c, pd_utility_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V2(
    parser_context_t* c, pd_utility_as_derivative_V2_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V2(
    parser_context_t* c, pd_utility_batch_all_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(
    parser_context_t* c, pd_system_fill_block_V2_t* m)
{
    CHECK_ERROR(_readPerbill_V2(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(
    parser_context_t* c, pd_system_set_heap_pages_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(
    parser_context_t* c, pd_system_set_code_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V2(
    parser_context_t* c, pd_system_remark_with_event_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(
    parser_context_t* c, pd_timestamp_set_V2_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V2(
    parser_context_t* c, pd_indices_claim_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V2(
    parser_context_t* c, pd_indices_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V2(
    parser_context_t* c, pd_indices_free_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V2(
    parser_context_t* c, pd_indices_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V2(
    parser_context_t* c, pd_indices_freeze_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(
    parser_context_t* c, pd_balances_set_balance_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V2(
    parser_context_t* c, pd_balances_force_unreserve_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(
    parser_context_t* c, pd_staking_set_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(
    parser_context_t* c, pd_staking_increase_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V2(
    parser_context_t *c, pd_staking_scale_validator_count_V2_t *m)
{
    CHECK_ERROR(_readPercent_V2(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(
    parser_context_t* c, pd_staking_force_no_eras_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(
    parser_context_t* c, pd_staking_force_new_era_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(
    parser_context_t *c, pd_staking_set_invulnerables_V2_t *m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(
    parser_context_t* c, pd_staking_force_unstake_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
    parser_context_t* c, pd_staking_force_new_era_always_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(
    parser_context_t *c, pd_staking_cancel_deferred_slash_V2_t *m)
{
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(
    parser_context_t* c, pd_staking_set_history_depth_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(
    parser_context_t* c, pd_staking_reap_stash_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V2(
    parser_context_t* c, pd_staking_kick_V2_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V2(
    parser_context_t *c, pd_staking_set_staking_configs_V2_t *m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT_V2(c, &m->min_nominator_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT_V2(c, &m->min_validator_bond))
    CHECK_ERROR(_readConfigOpu32_V2(c, &m->max_nominator_count))
    CHECK_ERROR(_readConfigOpu32_V2(c, &m->max_validator_count))
    CHECK_ERROR(_readConfigOpPercent_V2(c, &m->chill_threshold))
    CHECK_ERROR(_readConfigOpPerbill_V2(c, &m->min_commission))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V2(
    parser_context_t* c, pd_staking_chill_other_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V2(
    parser_context_t* c, pd_staking_force_apply_min_commission_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V2(
    parser_context_t* c, pd_grandpa_note_stalled_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V2(
    parser_context_t* c, pd_democracy_propose_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V2(
    parser_context_t* c, pd_democracy_second_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V2(
    parser_context_t* c, pd_democracy_vote_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V2(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V2(
    parser_context_t* c, pd_democracy_emergency_cancel_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V2(
    parser_context_t* c, pd_democracy_external_propose_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V2(
    parser_context_t* c, pd_democracy_external_propose_majority_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V2(
    parser_context_t* c, pd_democracy_external_propose_default_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V2(
    parser_context_t* c, pd_democracy_fast_track_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V2(
    parser_context_t* c, pd_democracy_veto_external_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V2(
    parser_context_t* c, pd_democracy_cancel_referendum_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V2(
    parser_context_t* c, pd_democracy_cancel_queued_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V2(
    parser_context_t* c, pd_democracy_delegate_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->to))
    CHECK_ERROR(_readConviction_V2(c, &m->conviction))
    CHECK_ERROR(_readBalance(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V2(
    parser_context_t* c, pd_democracy_undelegate_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V2(
    parser_context_t* c, pd_democracy_clear_public_proposals_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V2(
    parser_context_t* c, pd_democracy_note_preimage_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V2(
    parser_context_t* c, pd_democracy_note_preimage_operational_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V2(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V2(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V2(
    parser_context_t* c, pd_democracy_reap_preimage_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V2(
    parser_context_t* c, pd_democracy_unlock_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V2(
    parser_context_t* c, pd_democracy_remove_vote_V2_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V2(
    parser_context_t* c, pd_democracy_remove_other_vote_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V2(
    parser_context_t* c, pd_democracy_enact_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_blacklist_V2(
    parser_context_t *c, pd_democracy_blacklist_V2_t *m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readOptionu32(c, &m->maybe_ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V2(
    parser_context_t* c, pd_democracy_cancel_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V2(
    parser_context_t* c, pd_council_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V2(
    parser_context_t* c, pd_council_close_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_council_propose_V2(
    parser_context_t *c, pd_council_propose_V2_t *m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V2(
    parser_context_t *c, pd_council_set_members_V2_t *m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V2(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V2(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V2(
    parser_context_t *c, pd_council_execute_V2_t *m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V2(
    parser_context_t* c, pd_council_disapprove_proposal_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V2(
    parser_context_t* c, pd_treasury_propose_spend_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V2(
    parser_context_t* c, pd_treasury_reject_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V2(
    parser_context_t* c, pd_treasury_approve_proposal_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V2(
    parser_context_t* c, pd_vesting_vest_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V2(
    parser_context_t* c, pd_vesting_vest_other_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V2(
    parser_context_t *c, pd_vesting_vested_transfer_V2_t *m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V2(
    parser_context_t *c, pd_vesting_force_vested_transfer_V2_t *m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    CHECK_ERROR(_readVestingInfo(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V2(
    parser_context_t* c, pd_vesting_merge_schedules_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V2(
    parser_context_t* c, pd_identity_set_identity_V2_t* m)
{
    CHECK_ERROR(_readIdentityInfo(c, &m->info))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V2(
    parser_context_t* c, pd_identity_set_subs_V2_t* m)
{
    CHECK_ERROR(_readVecTupleAccountIdData_V2(c, &m->subs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V2(
    parser_context_t *c, pd_identity_add_registrar_V2_t *m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V2(
    parser_context_t* c, pd_identity_clear_identity_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V2(
    parser_context_t* c, pd_identity_request_judgement_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V2(
    parser_context_t* c, pd_identity_cancel_request_V2_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V2(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V2(
    parser_context_t* c, pd_identity_set_fee_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V2(
    parser_context_t* c, pd_identity_set_account_id_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V2(
    parser_context_t* c, pd_identity_provide_judgement_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    CHECK_ERROR(_readJudgementBalanceOfT_V2(c, &m->judgement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V2(
    parser_context_t* c, pd_identity_kill_identity_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V2(
    parser_context_t* c, pd_identity_add_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V2(
    parser_context_t* c, pd_identity_rename_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->sub))
    CHECK_ERROR(_readData(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V2(
    parser_context_t* c, pd_identity_remove_sub_V2_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V2(
    parser_context_t* c, pd_identity_quit_sub_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V2(
    parser_context_t* c, pd_bounties_propose_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V2(
    parser_context_t* c, pd_bounties_approve_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V2(
    parser_context_t* c, pd_bounties_propose_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V2(
    parser_context_t* c, pd_bounties_unassign_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V2(
    parser_context_t* c, pd_bounties_accept_curator_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V2(
    parser_context_t* c, pd_bounties_award_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V2(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V2(
    parser_context_t* c, pd_bounties_claim_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V2(
    parser_context_t* c, pd_bounties_close_bounty_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V2(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V2(
    parser_context_t* c, pd_tips_report_awesome_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V2(
    parser_context_t* c, pd_tips_retract_tip_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V2(
    parser_context_t* c, pd_tips_tip_new_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V2(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V2(
    parser_context_t* c, pd_tips_tip_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V2(
    parser_context_t* c, pd_tips_close_tip_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V2(
    parser_context_t* c, pd_tips_slash_tip_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->basic.balances_transfer_all_V2))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->basic.staking_bond_V2))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->basic.staking_bond_extra_V2))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->basic.staking_unbond_V2))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->basic.staking_withdraw_unbonded_V2))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->basic.staking_validate_V2))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->basic.staking_nominate_V2))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->basic.staking_chill_V2))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->basic.staking_set_payee_V2))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->basic.staking_set_controller_V2))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->basic.staking_payout_stakers_V2))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->basic.staking_rebond_V2))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->basic.session_set_keys_V2))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->basic.session_purge_keys_V2))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->basic.utility_batch_V2))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V2(c, &method->basic.utility_as_derivative_V2))
        break;
    case 258: /* module 1 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V2(c, &method->basic.utility_batch_all_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V2(c, &method->nested.system_remark_with_event_V2))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V2(c, &method->basic.timestamp_set_V2))
        break;
    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V2(c, &method->basic.indices_claim_V2))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V2(c, &method->basic.indices_transfer_V2))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V2(c, &method->basic.indices_free_V2))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V2(c, &method->basic.indices_force_transfer_V2))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V2(c, &method->basic.indices_freeze_V2))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V2(c, &method->basic.balances_force_unreserve_V2))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->basic.staking_set_validator_count_V2))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V2(c, &method->basic.staking_increase_validator_count_V2))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V2(c, &method->basic.staking_scale_validator_count_V2))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->basic.staking_force_no_eras_V2))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->basic.staking_force_new_era_V2))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->basic.staking_set_invulnerables_V2))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->basic.staking_force_unstake_V2))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->basic.staking_force_new_era_always_V2))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V2(c, &method->basic.staking_cancel_deferred_slash_V2))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V2(c, &method->basic.staking_set_history_depth_V2))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->basic.staking_reap_stash_V2))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V2(c, &method->basic.staking_kick_V2))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_set_staking_configs_V2(c, &method->basic.staking_set_staking_configs_V2))
        break;
    case 2072: /* module 8 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V2(c, &method->basic.staking_chill_other_V2))
        break;
    case 2073: /* module 8 call 25 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V2(c, &method->basic.staking_force_apply_min_commission_V2))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V2(c, &method->basic.grandpa_note_stalled_V2))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V2(c, &method->basic.democracy_propose_V2))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V2(c, &method->basic.democracy_second_V2))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V2(c, &method->basic.democracy_vote_V2))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V2(c, &method->basic.democracy_emergency_cancel_V2))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V2(c, &method->basic.democracy_external_propose_V2))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V2(c, &method->basic.democracy_external_propose_majority_V2))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V2(c, &method->basic.democracy_external_propose_default_V2))
        break;
    case 2567: /* module 10 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V2(c, &method->basic.democracy_fast_track_V2))
        break;
    case 2568: /* module 10 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V2(c, &method->basic.democracy_veto_external_V2))
        break;
    case 2569: /* module 10 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V2(c, &method->basic.democracy_cancel_referendum_V2))
        break;
    case 2570: /* module 10 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V2(c, &method->basic.democracy_cancel_queued_V2))
        break;
    case 2571: /* module 10 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V2(c, &method->basic.democracy_delegate_V2))
        break;
    case 2572: /* module 10 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V2(c, &method->basic.democracy_undelegate_V2))
        break;
    case 2573: /* module 10 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V2(c, &method->basic.democracy_clear_public_proposals_V2))
        break;
    case 2574: /* module 10 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V2(c, &method->basic.democracy_note_preimage_V2))
        break;
    case 2575: /* module 10 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V2(c, &method->basic.democracy_note_preimage_operational_V2))
        break;
    case 2576: /* module 10 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V2(c, &method->basic.democracy_note_imminent_preimage_V2))
        break;
    case 2577: /* module 10 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V2(c, &method->basic.democracy_note_imminent_preimage_operational_V2))
        break;
    case 2578: /* module 10 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V2(c, &method->basic.democracy_reap_preimage_V2))
        break;
    case 2579: /* module 10 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V2(c, &method->basic.democracy_unlock_V2))
        break;
    case 2580: /* module 10 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V2(c, &method->basic.democracy_remove_vote_V2))
        break;
    case 2581: /* module 10 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V2(c, &method->basic.democracy_remove_other_vote_V2))
        break;
    case 2582: /* module 10 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V2(c, &method->basic.democracy_enact_proposal_V2))
        break;
    case 2583: /* module 10 call 23 */
        CHECK_ERROR(_readMethod_democracy_blacklist_V2(c, &method->basic.democracy_blacklist_V2))
        break;
    case 2584: /* module 10 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V2(c, &method->basic.democracy_cancel_proposal_V2))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V2(c, &method->basic.council_set_members_V2))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V2(c, &method->nested.council_execute_V2))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V2(c, &method->nested.council_propose_V2))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V2(c, &method->basic.council_vote_V2))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_council_close_V2(c, &method->basic.council_close_V2))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V2(c, &method->basic.council_disapprove_proposal_V2))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V2(c, &method->basic.treasury_propose_spend_V2))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V2(c, &method->basic.treasury_reject_proposal_V2))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V2(c, &method->basic.treasury_approve_proposal_V2))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V2(c, &method->basic.vesting_vest_V2))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V2(c, &method->basic.vesting_vest_other_V2))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V2(c, &method->basic.vesting_vested_transfer_V2))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V2(c, &method->basic.vesting_force_vested_transfer_V2))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V2(c, &method->basic.vesting_merge_schedules_V2))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V2(c, &method->basic.identity_add_registrar_V2))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_identity_set_identity_V2(c, &method->basic.identity_set_identity_V2))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_identity_set_subs_V2(c, &method->basic.identity_set_subs_V2))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V2(c, &method->basic.identity_clear_identity_V2))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V2(c, &method->basic.identity_request_judgement_V2))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V2(c, &method->basic.identity_cancel_request_V2))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V2(c, &method->basic.identity_set_fee_V2))
        break;
    case 5895: /* module 23 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V2(c, &method->basic.identity_set_account_id_V2))
        break;
    case 5897: /* module 23 call 9 */
        CHECK_ERROR(_readMethod_identity_provide_judgement_V2(c, &method->basic.identity_provide_judgement_V2))
        break;
    case 5898: /* module 23 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V2(c, &method->basic.identity_kill_identity_V2))
        break;
    case 5899: /* module 23 call 11 */
        CHECK_ERROR(_readMethod_identity_add_sub_V2(c, &method->basic.identity_add_sub_V2))
        break;
    case 5900: /* module 23 call 12 */
        CHECK_ERROR(_readMethod_identity_rename_sub_V2(c, &method->basic.identity_rename_sub_V2))
        break;
    case 5901: /* module 23 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V2(c, &method->basic.identity_remove_sub_V2))
        break;
    case 5902: /* module 23 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V2(c, &method->basic.identity_quit_sub_V2))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V2(c, &method->basic.bounties_propose_bounty_V2))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V2(c, &method->basic.bounties_approve_bounty_V2))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V2(c, &method->basic.bounties_propose_curator_V2))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V2(c, &method->basic.bounties_unassign_curator_V2))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V2(c, &method->basic.bounties_accept_curator_V2))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V2(c, &method->basic.bounties_award_bounty_V2))
        break;
    case 9478: /* module 37 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V2(c, &method->basic.bounties_claim_bounty_V2))
        break;
    case 9479: /* module 37 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V2(c, &method->basic.bounties_close_bounty_V2))
        break;
    case 9480: /* module 37 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V2(c, &method->basic.bounties_extend_bounty_expiry_V2))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V2(c, &method->basic.tips_report_awesome_V2))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V2(c, &method->basic.tips_retract_tip_V2))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V2(c, &method->basic.tips_tip_new_V2))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V2(c, &method->basic.tips_tip_V2))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V2(c, &method->basic.tips_close_tip_V2))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V2(c, &method->basic.tips_slash_tip_V2))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 6:
        return STR_MO_BALANCES;
    case 8:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
    case 1:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 5:
        return STR_MO_INDICES;
    case 14:
        return STR_MO_GRANDPA;
    case 10:
        return STR_MO_DEMOCRACY;
    case 11:
        return STR_MO_COUNCIL;
    case 15:
        return STR_MO_TREASURY;
    case 25:
        return STR_MO_VESTING;
    case 23:
        return STR_MO_IDENTITY;
    case 37:
        return STR_MO_BOUNTIES;
    case 38:
        return STR_MO_TIPS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER;
    case 1538: /* module 6 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1540: /* module 6 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 2048: /* module 8 call 0 */
        return STR_ME_BOND;
    case 2049: /* module 8 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2050: /* module 8 call 2 */
        return STR_ME_UNBOND;
    case 2051: /* module 8 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2052: /* module 8 call 4 */
        return STR_ME_VALIDATE;
    case 2053: /* module 8 call 5 */
        return STR_ME_NOMINATE;
    case 2054: /* module 8 call 6 */
        return STR_ME_CHILL;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_PAYEE;
    case 2056: /* module 8 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2066: /* module 8 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2067: /* module 8 call 19 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 257: /* module 1 call 1 */
        return STR_ME_AS_DERIVATIVE;
    case 258: /* module 1 call 2 */
        return STR_ME_BATCH_ALL;
    default:
        return _getMethod_Name_V2_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V2_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 768: /* module 3 call 0 */
        return STR_ME_SET;
    case 1280: /* module 5 call 0 */
        return STR_ME_CLAIM;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER;
    case 1282: /* module 5 call 2 */
        return STR_ME_FREE;
    case 1283: /* module 5 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 1284: /* module 5 call 4 */
        return STR_ME_FREEZE;
    case 1537: /* module 6 call 1 */
        return STR_ME_SET_BALANCE;
    case 1541: /* module 6 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 2057: /* module 8 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2058: /* module 8 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2059: /* module 8 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 2060: /* module 8 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 2061: /* module 8 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 2062: /* module 8 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 2063: /* module 8 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 2064: /* module 8 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2065: /* module 8 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2068: /* module 8 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 2069: /* module 8 call 21 */
        return STR_ME_REAP_STASH;
    case 2070: /* module 8 call 22 */
        return STR_ME_KICK;
    case 2071: /* module 8 call 23 */
        return STR_ME_SET_STAKING_CONFIGS;
    case 2072: /* module 8 call 24 */
        return STR_ME_CHILL_OTHER;
    case 2073: /* module 8 call 25 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 3586: /* module 14 call 2 */
        return STR_ME_NOTE_STALLED;
    case 2560: /* module 10 call 0 */
        return STR_ME_PROPOSE;
    case 2561: /* module 10 call 1 */
        return STR_ME_SECOND;
    case 2562: /* module 10 call 2 */
        return STR_ME_VOTE;
    case 2563: /* module 10 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2564: /* module 10 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2565: /* module 10 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2566: /* module 10 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2567: /* module 10 call 7 */
        return STR_ME_FAST_TRACK;
    case 2568: /* module 10 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2569: /* module 10 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 2570: /* module 10 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 2571: /* module 10 call 11 */
        return STR_ME_DELEGATE;
    case 2572: /* module 10 call 12 */
        return STR_ME_UNDELEGATE;
    case 2573: /* module 10 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 2574: /* module 10 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2575: /* module 10 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2576: /* module 10 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2577: /* module 10 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2578: /* module 10 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2579: /* module 10 call 19 */
        return STR_ME_UNLOCK;
    case 2580: /* module 10 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2581: /* module 10 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2582: /* module 10 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 2583: /* module 10 call 23 */
        return STR_ME_BLACKLIST;
    case 2584: /* module 10 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 2816: /* module 11 call 0 */
        return STR_ME_SET_MEMBERS;
    case 2817: /* module 11 call 1 */
        return STR_ME_EXECUTE;
    case 2818: /* module 11 call 2 */
        return STR_ME_PROPOSE;
    case 2819: /* module 11 call 3 */
        return STR_ME_VOTE;
    case 2820: /* module 11 call 4 */
        return STR_ME_CLOSE;
    case 2821: /* module 11 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 3841: /* module 15 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 3842: /* module 15 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 6400: /* module 25 call 0 */
        return STR_ME_VEST;
    case 6401: /* module 25 call 1 */
        return STR_ME_VEST_OTHER;
    case 6402: /* module 25 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 6403: /* module 25 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 6404: /* module 25 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 5888: /* module 23 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 5889: /* module 23 call 1 */
        return STR_ME_SET_IDENTITY;
    case 5890: /* module 23 call 2 */
        return STR_ME_SET_SUBS;
    case 5891: /* module 23 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 5892: /* module 23 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 5893: /* module 23 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 5894: /* module 23 call 6 */
        return STR_ME_SET_FEE;
    case 5895: /* module 23 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 5897: /* module 23 call 9 */
        return STR_ME_PROVIDE_JUDGEMENT;
    case 5898: /* module 23 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 5899: /* module 23 call 11 */
        return STR_ME_ADD_SUB;
    case 5900: /* module 23 call 12 */
        return STR_ME_RENAME_SUB;
    case 5901: /* module 23 call 13 */
        return STR_ME_REMOVE_SUB;
    case 5902: /* module 23 call 14 */
        return STR_ME_QUIT_SUB;
    case 9472: /* module 37 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 9473: /* module 37 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 9474: /* module 37 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 9475: /* module 37 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 9476: /* module 37 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 9477: /* module 37 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 9478: /* module 37 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 9479: /* module 37 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 9480: /* module 37 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 9728: /* module 38 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 9729: /* module 38 call 1 */
        return STR_ME_RETRACT_TIP;
    case 9730: /* module 38 call 2 */
        return STR_ME_TIP_NEW;
    case 9731: /* module 38 call 3 */
        return STR_ME_TIP;
    case 9732: /* module 38 call 4 */
        return STR_ME_CLOSE_TIP;
    case 9733: /* module 38 call 5 */
        return STR_ME_SLASH_TIP;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return 2;
    case 1538: /* module 6 call 2 */
        return 3;
    case 1539: /* module 6 call 3 */
        return 2;
    case 1540: /* module 6 call 4 */
        return 2;
    case 2048: /* module 8 call 0 */
        return 3;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2066: /* module 8 call 18 */
        return 2;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
    case 256: /* module 1 call 0 */
        return 1;
    case 257: /* module 1 call 1 */
        return 1;
    case 258: /* module 1 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 1280: /* module 5 call 0 */
        return 1;
    case 1281: /* module 5 call 1 */
        return 2;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 1;
    case 1537: /* module 6 call 1 */
        return 3;
    case 1541: /* module 6 call 5 */
        return 2;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 1;
    case 2060: /* module 8 call 12 */
        return 0;
    case 2061: /* module 8 call 13 */
        return 0;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 2;
    case 2064: /* module 8 call 16 */
        return 0;
    case 2065: /* module 8 call 17 */
        return 2;
    case 2068: /* module 8 call 20 */
        return 2;
    case 2069: /* module 8 call 21 */
        return 2;
    case 2070: /* module 8 call 22 */
        return 1;
    case 2071: /* module 8 call 23 */
        return 6;
    case 2072: /* module 8 call 24 */
        return 1;
    case 2073: /* module 8 call 25 */
        return 1;
    case 3586: /* module 14 call 2 */
        return 2;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 2;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 1;
    case 2566: /* module 10 call 6 */
        return 1;
    case 2567: /* module 10 call 7 */
        return 3;
    case 2568: /* module 10 call 8 */
        return 1;
    case 2569: /* module 10 call 9 */
        return 1;
    case 2570: /* module 10 call 10 */
        return 1;
    case 2571: /* module 10 call 11 */
        return 3;
    case 2572: /* module 10 call 12 */
        return 0;
    case 2573: /* module 10 call 13 */
        return 0;
    case 2574: /* module 10 call 14 */
        return 1;
    case 2575: /* module 10 call 15 */
        return 1;
    case 2576: /* module 10 call 16 */
        return 1;
    case 2577: /* module 10 call 17 */
        return 1;
    case 2578: /* module 10 call 18 */
        return 2;
    case 2579: /* module 10 call 19 */
        return 1;
    case 2580: /* module 10 call 20 */
        return 1;
    case 2581: /* module 10 call 21 */
        return 2;
    case 2582: /* module 10 call 22 */
        return 2;
    case 2583: /* module 10 call 23 */
        return 2;
    case 2584: /* module 10 call 24 */
        return 1;
    case 2816: /* module 11 call 0 */
        return 3;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2818: /* module 11 call 2 */
        return 3;
    case 2819: /* module 11 call 3 */
        return 3;
    case 2820: /* module 11 call 4 */
        return 4;
    case 2821: /* module 11 call 5 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 2;
    case 3841: /* module 15 call 1 */
        return 1;
    case 3842: /* module 15 call 2 */
        return 1;
    case 6400: /* module 25 call 0 */
        return 0;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 2;
    case 6403: /* module 25 call 3 */
        return 3;
    case 6404: /* module 25 call 4 */
        return 2;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5889: /* module 23 call 1 */
        return 1;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 0;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 2;
    case 5895: /* module 23 call 7 */
        return 2;
    case 5897: /* module 23 call 9 */
        return 3;
    case 5898: /* module 23 call 10 */
        return 1;
    case 5899: /* module 23 call 11 */
        return 2;
    case 5900: /* module 23 call 12 */
        return 2;
    case 5901: /* module 23 call 13 */
        return 1;
    case 5902: /* module 23 call 14 */
        return 0;
    case 9472: /* module 37 call 0 */
        return 2;
    case 9473: /* module 37 call 1 */
        return 1;
    case 9474: /* module 37 call 2 */
        return 3;
    case 9475: /* module 37 call 3 */
        return 1;
    case 9476: /* module 37 call 4 */
        return 1;
    case 9477: /* module 37 call 5 */
        return 2;
    case 9478: /* module 37 call 6 */
        return 1;
    case 9479: /* module 37 call 7 */
        return 1;
    case 9480: /* module 37 call 8 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 1;
    case 9730: /* module 38 call 2 */
        return 3;
    case 9731: /* module 38 call 3 */
        return 2;
    case 9732: /* module 38 call 4 */
        return 1;
    case 9733: /* module 38 call 5 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
           return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_min_nominator_bond;
        case 1:
            return STR_IT_min_validator_bond;
        case 2:
            return STR_IT_max_nominator_count;
        case 3:
            return STR_IT_max_validator_count;
        case 4:
            return STR_IT_chill_threshold;
        case 5:
            return STR_IT_min_commission;
        default:
            return NULL;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2569: /* module 10 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2570: /* module 10 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2573: /* module 10 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2582: /* module 10 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2583: /* module 10 call 23 */
        switch (itemIdx)
    {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_maybe_ref_index;
        default:
            return NULL;
        }
    case 2584: /* module 10 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx)
        {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_info;
        default:
            return NULL;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_subs;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_judgement;
        default:
            return NULL;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        case 1:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_transfer_keep_alive_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V2 - dest */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.balances_transfer_all_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V2 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V2.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V2 - controller */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.staking_bond_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_bond_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V2 - prefs */;
            return _toStringValidatorPrefs_V2(
                &m->basic.staking_validate_V2.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V2 - targets */;
            return _toStringVecLookupasStaticLookupSource_V2(
                &m->basic.staking_nominate_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->basic.staking_set_payee_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V2 - controller */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.staking_set_controller_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_payout_stakers_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_payout_stakers_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V2 - keys */;
            return _toStringKeys_V2(
                &m->basic.session_set_keys_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V2 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V2.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V2 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V2 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 258: /* module 1 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V2 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V2 - ratio */;
            return _toStringPerbill_V2(
                &m->nested.system_fill_block_V2.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V2 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V2.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V2 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V2 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V2.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_claim_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_free_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.indices_force_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_force_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V2 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V2.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->basic.indices_freeze_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->nested.balances_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V2 - who */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.balances_force_unreserve_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V2 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V2 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V2 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V2.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx)
        {
        case 0: /* staking_scale_validator_count_V2 - factor */;
            return _toStringPercent_V2(
                &m->basic.staking_scale_validator_count_V2.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx)
        {
        case 0: /* staking_set_invulnerables_V2 - invulnerables */;
            return _toStringVecAccountId_V2(
                &m->basic.staking_set_invulnerables_V2.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_force_unstake_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx)
        {
        case 0: /* staking_cancel_deferred_slash_V2 - era */;
            return _toStringEraIndex_V2(
                &m->basic.staking_cancel_deferred_slash_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V2.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V2 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V2 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V2.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V2 - stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_reap_stash_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V2 - who */;
            return _toStringVecLookupasStaticLookupSource_V2(
                &m->basic.staking_kick_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx)
        {
        case 0: /* staking_set_staking_configs_V2 - min_nominator_bond */;
            return _toStringConfigOpBalanceOfT_V2(
                &m->basic.staking_set_staking_configs_V2.min_nominator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_staking_configs_V2 - min_validator_bond */;
            return _toStringConfigOpBalanceOfT_V2(
                &m->basic.staking_set_staking_configs_V2.min_validator_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_set_staking_configs_V2 - max_nominator_count */;
            return _toStringConfigOpu32_V2(
                &m->basic.staking_set_staking_configs_V2.max_nominator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_set_staking_configs_V21 - max_validator_count */;
            return _toStringConfigOpu32_V2(
                &m->basic.staking_set_staking_configs_V2.max_validator_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_set_staking_configs_V2 - chill_threshold */;
            return _toStringConfigOpPercent_V2(
                &m->basic.staking_set_staking_configs_V2.chill_threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* staking_set_staking_configs_V2 - min_commission */;
            return _toStringConfigOpPerbill_V2(
                &m->basic.staking_set_staking_configs_V2.min_commission,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V2 - controller */;
            return _toStringAccountId_V2(
                &m->basic.staking_chill_other_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->basic.staking_force_apply_min_commission_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V2 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V2.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.democracy_propose_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V2 - proposal */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V2 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V2.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V2 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_vote_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V2 - vote */;
            return _toStringAccountVote_V2(
                &m->basic.democracy_vote_V2.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V2 - ref_index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_emergency_cancel_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V2 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V2 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2569: /* module 10 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V2 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_referendum_V2.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2570: /* module 10 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V2 - which */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_cancel_queued_V2.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V2 - to */;
            return _toStringAccountId_V2(
                &m->basic.democracy_delegate_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V2 - conviction */;
            return _toStringConviction_V2(
                &m->basic.democracy_delegate_V2.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V2 - balance */;
            return _toStringBalance(
                &m->basic.democracy_delegate_V2.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2573: /* module 10 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V2 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V2.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V2 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V2.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V2 - target */;
            return _toStringAccountId_V2(
                &m->basic.democracy_unlock_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_remove_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V2 - target */;
            return _toStringAccountId_V2(
                &m->basic.democracy_remove_other_vote_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_remove_other_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2582: /* module 10 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_enact_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V2 - index */;
            return _toStringReferendumIndex_V2(
                &m->basic.democracy_enact_proposal_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2583: /* module 10 call 23 */
        switch (itemIdx)
        {
        case 0: /* democracy_blacklist_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_blacklist_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_blacklist_V2 - maybe_ref_index */;
            return _toStringOptionu32(
                &m->basic.democracy_blacklist_V2.maybe_ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2584: /* module 10 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V2 - prop_index */;
            return _toStringCompactu32(
                &m->basic.democracy_cancel_proposal_V2.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx)
        {
        case 0: /* council_set_members_V2 - new_members */;
            return _toStringVecAccountId_V2(
                &m->basic.council_set_members_V2.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V2 - prime */;
            return _toStringOptionAccountId_V2(
                &m->basic.council_set_members_V2.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V2 - old_count */;
            return _toStringMemberCount_V2(
                &m->basic.council_set_members_V2.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx)
        {
        case 0: /* council_execute_V2 - proposal */;
            return _toStringProposal(
                &m->nested.council_execute_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V2 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_execute_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx)
        {
        case 0: /* council_propose_V2 - threshold */;
            return _toStringCompactu32(
                &m->nested.council_propose_V2.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V2 - proposal */;
            return _toStringProposal(
                &m->nested.council_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V2 - length_bound */;
            return _toStringCompactu32(
                &m->nested.council_propose_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V2 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V2 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V2 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V2 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V2 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_V2.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V2 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V2.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V2 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V2.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V2 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.treasury_propose_spend_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V2 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V2 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.vesting_vest_other_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx)
        {
        case 0: /* vesting_vested_transfer_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.vesting_vested_transfer_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V2 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_vested_transfer_V2.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx)
        {
        case 0: /* vesting_force_vested_transfer_V2 - source */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.vesting_force_vested_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.vesting_force_vested_transfer_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V2 - schedule */;
            return _toStringVestingInfo(
                &m->basic.vesting_force_vested_transfer_V2.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V2 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V2.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V2 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V2.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V2 - account */;
            return _toStringAccountId_V2(
                &m->basic.identity_add_registrar_V2.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* identity_set_identity_V2 - info */;
            return _toStringIdentityInfo(
                &m->basic.identity_set_identity_V2.info,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* identity_set_subs_V2 - subs */;
            return _toStringVecTupleAccountIdData_V2(
                &m->basic.identity_set_subs_V2.subs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V2 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V2 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V2.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V2 - reg_index */;
            return _toStringRegistrarIndex_V2(
                &m->basic.identity_cancel_request_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V2 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V2 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5895: /* module 23 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V2 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->basic.identity_set_account_id_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5897: /* module 23 call 9 */
        switch (itemIdx) {
        case 0: /* identity_provide_judgement_V2 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_provide_judgement_V2.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_provide_judgement_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_provide_judgement_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_provide_judgement_V2 - judgement */;
            return _toStringJudgementBalanceOfT_V2(
                &m->basic.identity_provide_judgement_V2.judgement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5898: /* module 23 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V2 - target */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_kill_identity_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5899: /* module 23 call 11 */
        switch (itemIdx) {
        case 0: /* identity_add_sub_V2 - sub */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_add_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_sub_V2 - data */;
            return _toStringData(
                &m->basic.identity_add_sub_V2.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5900: /* module 23 call 12 */
        switch (itemIdx) {
        case 0: /* identity_rename_sub_V23 - sub */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_rename_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rename_sub_V23 - data */;
            return _toStringData(
                &m->basic.identity_rename_sub_V2.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5901: /* module 23 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V2 - sub */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.identity_remove_sub_V2.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5902: /* module 23 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V2 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V2 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V2.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V2 - curator */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.bounties_propose_curator_V2.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V2 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V2.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V2 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V2(
                &m->basic.bounties_award_bounty_V2.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V2 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V2.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V2 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V2.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V2 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V2.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V2 - who */;
            return _toStringAccountId_V2(
                &m->basic.tips_report_awesome_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V2 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V2.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V2 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V2.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V2 - who */;
            return _toStringAccountId_V2(
                &m->basic.tips_tip_new_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V2 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_new_V2.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V2 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V2.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V2 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_V2.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V2 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V2.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V2 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V2.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2063: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2069: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 768: // Timestamp:Set
    case 1280: // Indices:Claim
    case 1281: // Indices:Transfer
    case 1282: // Indices:Free
    case 1283: // Indices:Force transfer
    case 1284: // Indices:Freeze
    case 1540: // Balances:Transfer all
    case 1541: // Balances:Force unreserve
    case 2048: // Staking:Bond
    case 2049: // Staking:Bond extra
    case 2050: // Staking:Unbond
    case 2051: // Staking:Withdraw Unbonded
    case 2052: // Staking:Validate
    case 2053: // Staking:Nominate
    case 2054: // Staking:Chill
    case 2055: // Staking:Set payee
    case 2056: // Staking:Set controller
    case 2057: // Staking:Set validator count
    case 2058: // Staking:Increase validator count
    case 2059: // Staking:Scale validator count
    case 2060: // Staking:Force no eras
    case 2061: // Staking:Force new era
    case 2062: // Staking:Set invulnerables
    case 2063: // Staking:Force unstake
    case 2064: // Staking:Force new era always
    case 2065: // Staking:Cancel deferred slash
    case 2066: // Staking:Payout stakers
    case 2067: // Staking:Rebond
    case 2068: // Staking:Set history depth
    case 2069: // Staking:Reap stash
    case 2070: // Staking:Kick
    case 2071: // Staking:Set staking configs
    case 2072: // Staking:Chill other
    case 2073: // Staking:Force apply min commission
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 3586: // Grandpa:Note stalled
    case 2560: // Democracy:Propose
    case 2561: // Democracy:Second
    case 2562: // Democracy:Vote
    case 2563: // Democracy:Emergency cancel
    case 2564: // Democracy:External propose
    case 2565: // Democracy:External propose majority
    case 2566: // Democracy:External propose default
    case 2567: // Democracy:Fast track
    case 2568: // Democracy:Veto external
    case 2569: // Democracy:Cancel referendum
    case 2570: // Democracy:Cancel queued
    case 2571: // Democracy:Delegate
    case 2572: // Democracy:Undelegate
    case 2573: // Democracy:Clear public proposals
    case 2574: // Democracy:Note preimage
    case 2575: // Democracy:Note preimage operational
    case 2576: // Democracy:Note imminent preimage
    case 2577: // Democracy:Note imminent preimage operational
    case 2578: // Democracy:Reap preimage
    case 2579: // Democracy:Unlock
    case 2580: // Democracy:Remove vote
    case 2581: // Democracy:Remove other vote
    case 2582: // Democracy:Enact proposal
    case 2583: // Democracy:Blacklist
    case 2584: // Democracy:Cancel proposal
    case 2816:  // Council:Set members
    case 2819: // Council:Vote
    case 2820: // Council:Close
    case 2821: // Council:Disapprove proposal
    case 3840: // Treasury:Propose spend
    case 3841: // Treasury:Reject proposal
    case 3842: // Treasury:Approve proposal
    case 6400: // Vesting:Vest
    case 6401: // Vesting:Vest other
    case 6402:  // Vesting:Vested transfer
    case 6403: // Vesting:Force vested transfer
    case 6404: // Vesting:Merge schedules
    case 256: // Utility:Batch
    case 257: // Utility:As derivative
    case 258: // Utility:Batch all
    case 5888: // Identity:Add registrar
    case 5889: // Identity:Set identity
    case 5890: // Identity:Set subs
    case 5891: // Identity:Clear identity
    case 5892: // Identity:Request judgement
    case 5893: // Identity:Cancel request
    case 5894: // Identity:Set fee
    case 5895: // Identity:Set account id
    case 5897: // Identity:Provide judgement
    case 5898: // Identity:Kill identity
    case 5899: // Identity:Add sub
    case 5900: // Identity:Rename sub
    case 5901: // Identity:Remove sub
    case 5902: // Identity:Quit sub
    case 9472: // Bounties:Propose bounty
    case 9473: // Bounties:Approve bounty
    case 9474: // Bounties:Propose curator
    case 9475: // Bounties:Unassign curator
    case 9476: // Bounties:Accept curator
    case 9477: // Bounties:Award bounty
    case 9478: // Bounties:Claim bounty
    case 9479: // Bounties:Close bounty
    case 9480: // Bounties:Extend bounty expiry
    case 9728: // Tips:Report awesome
    case 9729: // Tips:Retract tip
    case 9730: // Tips:Tip new
    case 9731: // Tips:Tip
    case 9732: // Tips:Close tip
    case 9733: // Tips:Slash tip
        return false;
    default:
        return true;
    }
}