// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <graphqlservice/GraphQLService.h>

#include <memory>
#include <string>
#include <vector>

namespace facebook {
namespace graphql {
namespace introspection {

class Schema;

} /* namespace introspection */

namespace today {

enum class TaskState
{
	New,
	Started,
	Complete,
	Unassigned
};

struct CompleteTaskInput
{
	std::vector<uint8_t> id;
	std::unique_ptr<response::BooleanType> isComplete;
	std::unique_ptr<response::StringType> clientMutationId;
};

struct Node
{
	virtual std::future<std::vector<uint8_t>> getId(service::RequestId requestId) const = 0;
};

namespace object {

class Query;
class PageInfo;
class AppointmentEdge;
class AppointmentConnection;
class TaskEdge;
class TaskConnection;
class FolderEdge;
class FolderConnection;
class CompleteTaskPayload;
class Mutation;
class Subscription;
class Appointment;
class Task;
class Folder;

class Query
	: public service::Object
{
protected:
	Query();

public:
	virtual std::future<std::shared_ptr<service::Object>> getNode(service::RequestId requestId, std::vector<uint8_t>&& id) const = 0;
	virtual std::future<std::shared_ptr<AppointmentConnection>> getAppointments(service::RequestId requestId, std::unique_ptr<response::IntType>&& first, std::unique_ptr<response::Value>&& after, std::unique_ptr<response::IntType>&& last, std::unique_ptr<response::Value>&& before) const = 0;
	virtual std::future<std::shared_ptr<TaskConnection>> getTasks(service::RequestId requestId, std::unique_ptr<response::IntType>&& first, std::unique_ptr<response::Value>&& after, std::unique_ptr<response::IntType>&& last, std::unique_ptr<response::Value>&& before) const = 0;
	virtual std::future<std::shared_ptr<FolderConnection>> getUnreadCounts(service::RequestId requestId, std::unique_ptr<response::IntType>&& first, std::unique_ptr<response::Value>&& after, std::unique_ptr<response::IntType>&& last, std::unique_ptr<response::Value>&& before) const = 0;
	virtual std::future<std::vector<std::shared_ptr<Appointment>>> getAppointmentsById(service::RequestId requestId, std::vector<std::vector<uint8_t>>&& ids) const = 0;
	virtual std::future<std::vector<std::shared_ptr<Task>>> getTasksById(service::RequestId requestId, std::vector<std::vector<uint8_t>>&& ids) const = 0;
	virtual std::future<std::vector<std::shared_ptr<Folder>>> getUnreadCountsById(service::RequestId requestId, std::vector<std::vector<uint8_t>>&& ids) const = 0;

private:
	std::future<response::Value> resolveNode(service::ResolverParams&& params);
	std::future<response::Value> resolveAppointments(service::ResolverParams&& params);
	std::future<response::Value> resolveTasks(service::ResolverParams&& params);
	std::future<response::Value> resolveUnreadCounts(service::ResolverParams&& params);
	std::future<response::Value> resolveAppointmentsById(service::ResolverParams&& params);
	std::future<response::Value> resolveTasksById(service::ResolverParams&& params);
	std::future<response::Value> resolveUnreadCountsById(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
	std::future<response::Value> resolve__schema(service::ResolverParams&& params);
	std::future<response::Value> resolve__type(service::ResolverParams&& params);

	std::shared_ptr<introspection::Schema> _schema;
};

class PageInfo
	: public service::Object
{
protected:
	PageInfo();

public:
	virtual std::future<response::BooleanType> getHasNextPage(service::RequestId requestId) const = 0;
	virtual std::future<response::BooleanType> getHasPreviousPage(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveHasNextPage(service::ResolverParams&& params);
	std::future<response::Value> resolveHasPreviousPage(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class AppointmentEdge
	: public service::Object
{
protected:
	AppointmentEdge();

public:
	virtual std::future<std::shared_ptr<Appointment>> getNode(service::RequestId requestId) const = 0;
	virtual std::future<response::Value> getCursor(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveNode(service::ResolverParams&& params);
	std::future<response::Value> resolveCursor(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class AppointmentConnection
	: public service::Object
{
protected:
	AppointmentConnection();

public:
	virtual std::future<std::shared_ptr<PageInfo>> getPageInfo(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<AppointmentEdge>>>> getEdges(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolvePageInfo(service::ResolverParams&& params);
	std::future<response::Value> resolveEdges(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class TaskEdge
	: public service::Object
{
protected:
	TaskEdge();

public:
	virtual std::future<std::shared_ptr<Task>> getNode(service::RequestId requestId) const = 0;
	virtual std::future<response::Value> getCursor(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveNode(service::ResolverParams&& params);
	std::future<response::Value> resolveCursor(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class TaskConnection
	: public service::Object
{
protected:
	TaskConnection();

public:
	virtual std::future<std::shared_ptr<PageInfo>> getPageInfo(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<TaskEdge>>>> getEdges(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolvePageInfo(service::ResolverParams&& params);
	std::future<response::Value> resolveEdges(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class FolderEdge
	: public service::Object
{
protected:
	FolderEdge();

public:
	virtual std::future<std::shared_ptr<Folder>> getNode(service::RequestId requestId) const = 0;
	virtual std::future<response::Value> getCursor(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveNode(service::ResolverParams&& params);
	std::future<response::Value> resolveCursor(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class FolderConnection
	: public service::Object
{
protected:
	FolderConnection();

public:
	virtual std::future<std::shared_ptr<PageInfo>> getPageInfo(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<std::vector<std::shared_ptr<FolderEdge>>>> getEdges(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolvePageInfo(service::ResolverParams&& params);
	std::future<response::Value> resolveEdges(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class CompleteTaskPayload
	: public service::Object
{
protected:
	CompleteTaskPayload();

public:
	virtual std::future<std::shared_ptr<Task>> getTask(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getClientMutationId(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveTask(service::ResolverParams&& params);
	std::future<response::Value> resolveClientMutationId(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class Mutation
	: public service::Object
{
protected:
	Mutation();

public:
	virtual std::future<std::shared_ptr<CompleteTaskPayload>> getCompleteTask(service::RequestId requestId, CompleteTaskInput&& input) const = 0;

private:
	std::future<response::Value> resolveCompleteTask(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class Subscription
	: public service::Object
{
protected:
	Subscription();

public:
	virtual std::future<std::shared_ptr<Appointment>> getNextAppointmentChange(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveNextAppointmentChange(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class Appointment
	: public service::Object
	, public Node
{
protected:
	Appointment();

public:
	virtual std::future<std::unique_ptr<response::Value>> getWhen(service::RequestId requestId) const = 0;
	virtual std::future<std::unique_ptr<response::StringType>> getSubject(service::RequestId requestId) const = 0;
	virtual std::future<response::BooleanType> getIsNow(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveId(service::ResolverParams&& params);
	std::future<response::Value> resolveWhen(service::ResolverParams&& params);
	std::future<response::Value> resolveSubject(service::ResolverParams&& params);
	std::future<response::Value> resolveIsNow(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class Task
	: public service::Object
	, public Node
{
protected:
	Task();

public:
	virtual std::future<std::unique_ptr<response::StringType>> getTitle(service::RequestId requestId) const = 0;
	virtual std::future<response::BooleanType> getIsComplete(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveId(service::ResolverParams&& params);
	std::future<response::Value> resolveTitle(service::ResolverParams&& params);
	std::future<response::Value> resolveIsComplete(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

class Folder
	: public service::Object
	, public Node
{
protected:
	Folder();

public:
	virtual std::future<std::unique_ptr<response::StringType>> getName(service::RequestId requestId) const = 0;
	virtual std::future<response::IntType> getUnreadCount(service::RequestId requestId) const = 0;

private:
	std::future<response::Value> resolveId(service::ResolverParams&& params);
	std::future<response::Value> resolveName(service::ResolverParams&& params);
	std::future<response::Value> resolveUnreadCount(service::ResolverParams&& params);

	std::future<response::Value> resolve__typename(service::ResolverParams&& params);
};

} /* namespace object */

class Operations
	: public service::Request
{
public:
	Operations(std::shared_ptr<object::Query> query, std::shared_ptr<object::Mutation> mutation, std::shared_ptr<object::Subscription> subscription);

private:
	std::shared_ptr<object::Query> _query;
	std::shared_ptr<object::Mutation> _mutation;
	std::shared_ptr<object::Subscription> _subscription;
};

void AddTypesToSchema(std::shared_ptr<introspection::Schema> schema);

} /* namespace today */
} /* namespace graphql */
} /* namespace facebook */