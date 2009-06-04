//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'scheduletable_verif.cpp'                       *
//                        Generated by version 1.8.3                         *
//                       june 4th, 2009, at 10h25'8"                         *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 491
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "scheduletable_verif.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "scheduletable_verif.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "schedule_tables_well_formed"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_well_formed (C_Compiler & _inLexique,
                                const GGS_scheduletable_map   var_cas_sts COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_well_formed at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_484 (var_cas_sts, true) ;
    const GGS_scheduletable_map::cElement * operand_484 = NULL ;
    while (((operand_484 = enumerator_484.nextObject ()))) {
      macroValidPointer (operand_484) ;
      GGS_uint64  var_cas_len ;
      var_cas_len = GGS_uint64 (0U) ;
      { const GGS_basic_type _var_959 = operand_484->mInfo.st.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (21)) ; // CAST instruction
        if (_var_959.getPtr () != NULL) {
          macroValidPointer (_var_959.getPtr ()) ;
          if (typeid (cPtr_uint64_class) == typeid (* (_var_959.getPtr ()))) {
            const GGS_uint64_class var_cas_ui (_var_959.getPtr ()) ;
            var_cas_len = var_cas_ui.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (23)) ;
          }else{
            GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string ("Internal error, incorrect datatype for LENGTH attribute of Schedule Table "))._operator_concat (operand_484->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (25))) COMMA_SOURCE_FILE_AT_LINE (26)) ;
          }
        }
      }
      if (((var_cas_len)._operator_isEqual (GGS_uint64 (0U))).isBuiltAndTrue ()) {
        operand_484->mInfo.st.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (30)).reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (30)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("The LENGTH attribute should not be 0") COMMA_SOURCE_FILE_AT_LINE (31)) ;
      }
      GGS_action_list  var_cas_actions ;
      var_cas_actions = operand_484->mInfo.st.reader_actions (_inLexique COMMA_SOURCE_FILE_AT_LINE (33)) ;
      {
        GGS_action_list::cEnumerator enumerator_1239 (var_cas_actions, true) ;
        const GGS_action_list::cElement * operand_1239 = NULL ;
        while (((operand_1239 = enumerator_1239.nextObject ()))) {
          macroValidPointer (operand_1239) ;
          if (((operand_1239->offset)._operator_strictSup (var_cas_len)).isBuiltAndTrue ()) {
            operand_1239->act.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (38)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string ("Offset of action is greater than the LENGTH attribute of Schedule Table "))._operator_concat (operand_484->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (38))) COMMA_SOURCE_FILE_AT_LINE (39)) ;
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_well_formed\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//Implementation of routine "schedule_tables_counters_exist_and_compatible"  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_counters_exist_and_compatible (C_Compiler & _inLexique,
                                const GGS_scheduletable_map   var_cas_sts,
                                const GGS_counter_map   var_cas_cnts COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_counters_exist_and_compatible at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_1846 (var_cas_sts, true) ;
    const GGS_scheduletable_map::cElement * operand_1846 = NULL ;
    while (((operand_1846 = enumerator_1846.nextObject ()))) {
      macroValidPointer (operand_1846) ;
      GGS_lstring  var_cas_cnt ;
      var_cas_cnt = operand_1846->mInfo.st.reader_counter (_inLexique COMMA_SOURCE_FILE_AT_LINE (52)) ;
      if ((((var_cas_cnts.reader_hasKey (_inLexique, var_cas_cnt.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (54)) COMMA_SOURCE_FILE_AT_LINE (54)))._operator_not ())._operator_and ((var_cas_cnt.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (54)))._operator_isNotEqual (GGS_string ("SystemCounter")))).isBuiltAndTrue ()) {
        var_cas_cnt.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string ("counter "))._operator_concat (var_cas_cnt.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (55))))._operator_concat (GGS_string (" is not defined !")) COMMA_SOURCE_FILE_AT_LINE (56)) ;
      }else{
        GGS_uint64  var_cas_len ;
        var_cas_len = GGS_uint64 (0U) ;
        GGS_location  var_cas_loc ;
        var_cas_loc = GGS_location (_inLexique) ;
        { const GGS_basic_type _var_2352 = operand_1846->mInfo.st.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (59)) ; // CAST instruction
          if (_var_2352.getPtr () != NULL) {
            macroValidPointer (_var_2352.getPtr ()) ;
            if (typeid (cPtr_uint64_class) == typeid (* (_var_2352.getPtr ()))) {
              const GGS_uint64_class var_cas_ui (_var_2352.getPtr ()) ;
              var_cas_len = var_cas_ui.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (60)) ;
              var_cas_loc = var_cas_ui.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (60)) ;
            }else{
              GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string ("Internal error, incorrect datatype for LENGTH attribute of schedule table "))._operator_concat (operand_1846->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (61))) COMMA_SOURCE_FILE_AT_LINE (62)) ;
            }
          }
        }
        GGS_counter_obj  var_cas_cpt ;
        const GGS_counter_map  _temp_2517 = var_cas_cnts ;
        if (_temp_2517.isBuilt ()) {
          _temp_2517 (HERE)->method_getCounter (_inLexique, var_cas_cnt, var_cas_cpt COMMA_SOURCE_FILE_AT_LINE (67)) ;
        }
        GGS_uint64  var_cas_max ;
        var_cas_max = GGS_uint64 (0U) ;
        { const GGS_basic_type _var_2801 = var_cas_cpt.reader_max_allowed_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (70)) ; // CAST instruction
          if (_var_2801.getPtr () != NULL) {
            macroValidPointer (_var_2801.getPtr ()) ;
            if (typeid (cPtr_uint32_class) == typeid (* (_var_2801.getPtr ()))) {
              const GGS_uint32_class var_cas_ui (_var_2801.getPtr ()) ;
              var_cas_max = var_cas_ui.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (72)).reader_uint64 (_inLexique COMMA_SOURCE_FILE_AT_LINE (72)) ;
            }else{
              GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string ("Internal error, incorrect datatype for MAXALLOWEDVALUE attribute of counter "))._operator_concat (var_cas_cnt.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (74))) COMMA_SOURCE_FILE_AT_LINE (75)) ;
            }
          }
        }
        if (((var_cas_len)._operator_strictSup (var_cas_max)).isBuiltAndTrue ()) {
          var_cas_loc.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((GGS_string ("LENGTH of schedule table "))._operator_concat (operand_1846->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (78))))._operator_concat (GGS_string (" is greater than MAXALLOWEDVALUE of counter ")))._operator_concat (var_cas_cnt.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (78))) COMMA_SOURCE_FILE_AT_LINE (79)) ;
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_counters_exist_and_compatible\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//    Implementation of routine "schedule_tables_tasks_and_events_exist"     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_schedule_tables_tasks_and_events_exist (C_Compiler & _inLexique,
                                const GGS_root_obj   var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_schedule_tables_tasks_and_events_exist at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  {
    GGS_scheduletable_map::cEnumerator enumerator_3175 (var_cas_cpu.reader_scheduletables (_inLexique COMMA_SOURCE_FILE_AT_LINE (91)), true) ;
    const GGS_scheduletable_map::cElement * operand_3175 = NULL ;
    while (((operand_3175 = enumerator_3175.nextObject ()))) {
      macroValidPointer (operand_3175) ;
      {
        GGS_action_list::cEnumerator enumerator_3251 (operand_3175->mInfo.st.reader_actions (_inLexique COMMA_SOURCE_FILE_AT_LINE (92)), true) ;
        const GGS_action_list::cElement * operand_3251 = NULL ;
        while (((operand_3251 = enumerator_3251.nextObject ()))) {
          macroValidPointer (operand_3251) ;
          { const GGS_action_obj _var_4378 = operand_3251->act ; // CAST instruction
            if (_var_4378.getPtr () != NULL) {
              macroValidPointer (_var_4378.getPtr ()) ;
              if (typeid (cPtr_activatetask_action) == typeid (* (_var_4378.getPtr ()))) {
                const GGS_activatetask_action var_cas_ata (_var_4378.getPtr ()) ;
                if (((var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (95)).reader_hasKey (_inLexique, var_cas_ata.reader_task_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (95)).reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (95)) COMMA_SOURCE_FILE_AT_LINE (95)))._operator_not ()).isBuiltAndTrue ()) {
                  operand_3251->act.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (96)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("TASK attribute of action does not reference an existing task") COMMA_SOURCE_FILE_AT_LINE (97)) ;
                }
              }else if (typeid (cPtr_setevent_action) == typeid (* (_var_4378.getPtr ()))) {
                const GGS_setevent_action var_cas_sea (_var_4378.getPtr ()) ;
                if (((var_cas_cpu.reader_tasks (_inLexique COMMA_SOURCE_FILE_AT_LINE (99)).reader_hasKey (_inLexique, var_cas_sea.reader_task_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (99)).reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (99)) COMMA_SOURCE_FILE_AT_LINE (99)))._operator_not ()).isBuiltAndTrue ()) {
                  operand_3251->act.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (100)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("TASK attribute of action does not reference an existing task") COMMA_SOURCE_FILE_AT_LINE (101)) ;
                }
                if (((var_cas_cpu.reader_events (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)).reader_hasKey (_inLexique, var_cas_sea.reader_event_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)).reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (102)) COMMA_SOURCE_FILE_AT_LINE (102)))._operator_not ()).isBuiltAndTrue ()) {
                  operand_3251->act.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (103)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("EVENT attribute of action does not reference an existing event") COMMA_SOURCE_FILE_AT_LINE (104)) ;
                }
              }else if (typeid (cPtr_incrementcounter_action) == typeid (* (_var_4378.getPtr ()))) {
                const GGS_incrementcounter_action var_cas_ica (_var_4378.getPtr ()) ;
                if (((var_cas_cpu.reader_counters (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)).reader_hasKey (_inLexique, var_cas_ica.reader_counter_name (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)).reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (106)) COMMA_SOURCE_FILE_AT_LINE (106)))._operator_not ()).isBuiltAndTrue ()) {
                  operand_3251->act.reader_location (_inLexique COMMA_SOURCE_FILE_AT_LINE (107)).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string ("COUNTER attribute of action does not reference an existing counter") COMMA_SOURCE_FILE_AT_LINE (108)) ;
                }
              }else{
                operand_3175->mKey.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((GGS_string ("Internal error, incorrect datatype for ACTION attribute at offset "))._operator_concat (operand_3251->offset.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (110))))._operator_concat (GGS_string (" of schedule table ")))._operator_concat (operand_3175->mKey.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (110))) COMMA_SOURCE_FILE_AT_LINE (111)) ;
              }
            }
          }
        }
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_schedule_tables_tasks_and_events_exist\n") ;
  #endif
}

//---------------------------------------------------------------------------*

