// $Id: $

function jiscpmtask_project_tasks(_organization_select_id, _project_select, _task_select_id, _assign_select_id, _with_all_option, _all_text) {
  var task_select = $("#" + _task_select_id).get(0);
  jiscpm_empty_select(task_select);
  var project_nid = _project_select.value;
  if (!project_nid) project_nid=0;

  $.ajax({
    type: "GET",
    async: true,
    url: Drupal.settings.jiscpm.project_tasks_url + Drupal.encodeURIComponent(project_nid),
    dataType: "string",
    success: function (data) {
      var items = Drupal.parseJson(data);
      jiscpm_fill_select(task_select, items, _with_all_option, _all_text);
    }
  });

  var organization_select = $("#" + _organization_select_id).get(0);
  var organization_nid = organization_select.value;
  if (!organization_nid) organization_nid=0;
  var assign_select = $("#" + _assign_select_id).get(0);
  if (assign_select) {
    jiscpm_empty_select(assign_select);
    $.ajax({
      type: "GET",
      async: true,
      url: Drupal.settings.jiscpm.project_assignments_url + Drupal.encodeURIComponent(organization_nid) + '/' + Drupal.encodeURIComponent(project_nid),
      dataType: "string",
      success: function (data) {
        var items = Drupal.parseJson(data);
        jiscpm_fill_select(assign_select, items, false, _all_text);
      }
    });
  }
};

function jiscpmtask_organization_project_tasks(_organization_select, _project_select_id, _task_select_id, _assign_select_id, _with_all_option, _all_text) {
  jiscpmproject_organization_projects(_organization_select, _project_select_id, _with_all_option, _all_text);
  var project_select = $("#" + _project_select_id).get(0);
  var _organization_select_id = $(_organization_select).attr('id');
  jiscpmtask_project_tasks(_organization_select_id, project_select, _task_select_id, _assign_select_id, _with_all_option, _all_text);
};

